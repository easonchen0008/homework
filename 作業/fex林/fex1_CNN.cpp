
#include<iostream>
#include<math.h>
#include<map>
#include<fstream>
using namespace std;
const int MaxCol= 10;
const int MaxRow= 1000;
const int MaxK = 10;


class KNN{
  private:
    int m_k;
    int m_train_row;
    int m_test_row;
    int m_column;
    double TrainData[MaxRow][MaxCol];
    double TestData[MaxRow][MaxCol];
    int TrainLabels[MaxRow];
    int TestLabels[MaxRow];

  public:
    KNN(int k, char *FileName, int Row, int Column):m_k(k),m_column(Column){
      ifstream fin;
      fin.open(FileName,std::ios::in);
      fin.is_open();

      double Number;
      cout<<"please input the number of test data:"<<endl;
      cin>>Number;
      //assert(Number>0&&Number<Row);
      m_train_row = Row-Number;
      m_test_row = Number;
      for(int i = 0; i < m_test_row; i++){
        for(int j = 0; j < m_column; j++){
          fin>>TestData[i][j];
          cout<<TestData[i][j]<<" _ ";
        }
        fin>>TestLabels[i];
      }

      for(int i = 0; i < m_train_row; i++){
        for(int j = 0; j < m_column; j++){
          fin>>TrainData[i][j];
        }
        fin>>TrainLabels[i];
      }

      AutoNorm();
    }


    int Classify(double Input[]);
    int GetMaxSeq(int LabelMinIdx[]);
    int GetMinDistIndex(double Distance[]);
    double GetDistance(double[], double[]);
    double CorrectRate();
    void AutoNorm();
    void Print();
};

void KNN::Print(){
  cout<<"**************Train Data***************"<<endl;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < m_column; j++){
      cout<<TrainData[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"**************Test Data***************"<<endl;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < m_column; j++){
      cout<<TestData[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"distance = "<<GetDistance(TestData[0],TrainData[0])<<endl;;
}

void KNN::AutoNorm(){
  double TotalData[MaxRow][MaxCol];
  for(int i = 0; i < m_train_row; i++){
    for(int j = 0; j < m_column; j++){
      TotalData[i][j] = TrainData[i][j];
    }
  }

  for(int i = 0; i < m_test_row; i++){
    for(int j = 0; j < m_column; j++){
      TotalData[i+m_train_row][j] = TestData[i][j];
    }
  }

  double Min = -1;
  double Max = 9999;
  double MinMax[2][MaxCol];
  for(int j = 0; j < m_column; j++){
    Min = 9999; Max = -1;
    for(int i = 0; i < m_train_row + m_test_row; i++){
      if(TotalData[i][j] < Min) Min = TotalData[i][j];
      if(TotalData[i][j] > Max) Max = TotalData[i][j];
    }
    MinMax[0][j] = Min;
    MinMax[1][j] = Max;
  }

  for(int i = 0; i < m_train_row; i++){
    for(int j = 0; j < m_column; j++){
      TrainData[i][j] = (TrainData[i][j] - MinMax[0][j])/(MinMax[1][j] - MinMax[0][j]);
    }
  }

  for(int i = 0; i < m_test_row; i++){
    for(int j = 0; j < m_column; j++){
      TestData[i][j] = (TestData[i][j] - MinMax[0][j])/(MinMax[1][j] - MinMax[0][j]);
    }
  }
}


double KNN::GetDistance(double Input[], double TrainData[]){
  if(Input==nullptr){
    cout<<"error!"<<endl;
    return -9999;
  }

  double Distance = 0;
  for(int i = 0; i < m_column; i++){
    Distance += (Input[i] - TrainData[i]) * (Input[i] - TrainData[i]);
  }

  return sqrt(Distance);
}

int KNN::GetMinDistIndex(double Distance[]){
  int Index = -1;
  double DistMin = 99;
  if(Distance==nullptr){
    cout<<"error!"<<endl;
    return -9999;
  }
  for(int i = 0; i < m_train_row; i++){
    if(Distance[i]<DistMin&&Distance[i]>=0) {
      DistMin = Distance[i];
      Index = i;
    }
  }
  Distance[Index] = -1;//找出最小值後,將其置爲-1
  return Index;
}


int KNN::GetMaxSeq(int LabelMinIdx[]){
  map<int,int> LabelAppearTime;//key爲Label值，value爲出現次數
  map<int,int>::iterator iter;
  for(int i = 0; i < m_k; i++){
    iter = LabelAppearTime.find(TrainLabels[LabelMinIdx[i]]);
    if(iter!=LabelAppearTime.end()) iter->second++;
    else {
      LabelAppearTime.insert(pair<int,int>(TrainLabels[LabelMinIdx[i]],1));
    }
  }

  int LabelMaxSeq = -1;
  int times = 0;
  for(iter = LabelAppearTime.begin(); iter!=LabelAppearTime.end(); iter++){
    if(iter->second>times) {
      times = iter->second;
      LabelMaxSeq = iter->first;
    }
  }
  return LabelMaxSeq;
}





int KNN::Classify(double Input[]){
  //Column是數據特徵變量的個數
  //Row是DataSet的輸入向量的長度
  /*
  算法的基本思想是，計算Input向量與DataSet每個向量的距離，並用一個數組Distance儲存。
  找出Distance中的最小的前k個值，在Labels向量中找出對應下標並記錄對應Labels值
  找出記錄下的Labels值中，出現頻率最高的作爲返回值。

  */

  double Distance[MaxRow];
  for(int i = 0; i < m_train_row; i++){
    Distance[i] = GetDistance(Input,TrainData[i]);
  }


  int LabelMinIdx[MaxK];
  for(int i = 0;i < m_k; i++){
    LabelMinIdx[i] = GetMinDistIndex(Distance);//返回的是Label下標
  }
  return GetMaxSeq(LabelMinIdx);

}

double KNN::CorrectRate(){
  // 對於每個TestData，利用Classify獲得LabelsPredict，再和TestData的真實Label計算正確率
  double CorrectNum = 0;
  for(int i = 0; i < m_test_row; i++){
    if(Classify(TestData[i])==TestLabels[i]) CorrectNum++;
  }
  double CorrectRate = CorrectNum/m_test_row;
  cout<<"CorrectRate = "<<CorrectRate<<endl;
  return 0;
}





int main(){
  int k,row,col;

  char *FileName ;
/*  if(argc!=5){
    cout<<"The input should be like this : ./a.out k row col filename"<<endl;
    exit(1);
  }*/
    cout<<"input k"<<endl;
    k=7;
	row = 150;
	col = 5;
	FileName = "iris.txt";

  //KNN *k = new KNN(7,FileName,1000,3);
  KNN *knn= new KNN(k,FileName,row,col);
  knn->CorrectRate();
  knn->Print();
  return 0;
}
