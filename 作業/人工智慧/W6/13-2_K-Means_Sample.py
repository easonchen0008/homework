#基本範例
from sklearn.cluster import KMeans
import numpy as np

X = np.array([[1, 2], [1, 4], [1, 0], [10, 2], [10, 4], [10, 0]])
kmeans = KMeans(n_clusters=2,max_iter= 1,n_init= 1).fit(X)


print("labels =" ,kmeans.labels_)
print("predict =" ,kmeans.predict([[0, 0], [12, 3]]))
print("cluster_centers =" ,kmeans.cluster_centers_)

'''----------------------------------------------------------------'''
# Iris資料分群應用
from sklearn.datasets import load_iris

data = load_iris()
x=data['data']
y=data['target']

from sklearn.cluster import KMeans
kmeans = KMeans(n_clusters=3,max_iter= 1000,n_init=50,init='random').fit(x)
# 對比原本分群與kmeans結果
for i in range(3):
    print('cluster'+str(i)+': ', kmeans.labels_[y==i], end='\n\n')

'''----------------------------------------------------------------'''
#影像分群應用
# from cv2 import cv2, os

# files=os.listdir('image')
# x=[]
# for file in files:
#     img = cv2.imread('image/' + file)
#     lab = cv2.cvtColor(img, cv2.COLOR_BGR2LAB)
#     hist = cv2.calcHist(
#             [lab],
#             [0, 1, 2],
#             None,
#             [8,8,8],  # 將3通道值的頻率統計成直方圖，每通道8個直方圖
#             [0, 256, 0, 256, 0, 256])
#     hist = cv2.normalize(hist, None).ravel()
#     x.append(hist)

# from sklearn.cluster import KMeans
# import numpy as np
# import shutil

# kmeans = KMeans(n_clusters=10).fit(x)
# for i in range(10):
#     os.mkdir('output_K-Means/'+str(i))
# for i in range(10):
#     for j in np.where(kmeans.labels_==i)[0]:
#        shutil.copyfile('image/'+files[j], 'output_K-Means/'+str(i)+'/'+files[j])
