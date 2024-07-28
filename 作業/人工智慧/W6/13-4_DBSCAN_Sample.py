#自定義資料測試
from sklearn.cluster import DBSCAN
import numpy as np

# X = np.array([[1, 2], [2, 2], [2, 3], [8, 7], [8, 8], [25, 80]])
# clustering = DBSCAN(eps=0.8, min_samples=4,leaf_size= 5).fit(X)
# print(clustering.labels_)
# -1代表離群點

'''----------------------------------------------------------'''

# Iris資料集測試
# from sklearn.datasets import load_iris
#
# data = load_iris()
# x=data['data']
# y=data['target']
#
# from sklearn.cluster import DBSCAN
#
# dbscan = DBSCAN(eps=0.5, min_samples=4,leaf_size=60).fit(x)
# for i in range(3):
#     print('cluster'+str(i)+': ', dbscan.labels_[y==i], end='\n')

'''----------------------------------------------------------'''

#芒果資料集測試
# from cv2 import cv2, os

# files=os.listdir('image')
# x=[]
# for file in files:
#     img = cv2.imread('image/'+file)
#     lab = cv2.cvtColor(img, cv2.COLOR_BGR2LAB)
#     hist = cv2.calcHist(
#             [lab],
#             [0, 1, 2],
#             None,
#             [16,16,16],
#             [0, 256, 0, 256, 0, 256])
#     hist = cv2.normalize(hist, None).ravel()
#     x.append(hist)

# from sklearn.cluster import DBSCAN
# import numpy as np
# import shutil

# dbscan = DBSCAN(eps=0.6, min_samples=30).fit(x)
# for i in np.where(dbscan.labels_==-1)[0]:
#    shutil.copyfile('image/'+files[i], 'output_DBSCAN/'+files[i])

'''----------------------------------------------------------'''

# 產生資料圖
import matplotlib.pyplot as plt
from sklearn import datasets

X, y =datasets.make_circles(n_samples=6000, factor=0.2 ,noise =0.1 )

plt.scatter(X[:, 0], X[:, 1], marker= 'o' )
plt.show()

'''----------------------------------------------------------'''
#
# #K-Means分類
# from sklearn.cluster import KMeans
#
# y_pred = KMeans(n_clusters=3, random_state=1).fit_predict(X)
# plt.scatter(X[:, 0], X[:, 1], c= y_pred)
# plt.show()
#
# '''----------------------------------------------------------'''
#
# DBSCAN(eps=0.1)分類
from sklearn.cluster import DBSCAN

y_pred = DBSCAN(eps=0.1, min_samples=3,leaf_size=40).fit_predict(X)
plt.scatter(X[:, 0], X[:, 1], c= y_pred)
plt.show()

'''----------------------------------------------------------'''

#DBSCAN(eps=0.3)分類
# from sklearn.cluster import DBSCAN
# y_pred = DBSCAN(eps=0.3).fit_predict(X)
# plt.scatter(X[:, 0], X[:, 1], c= y_pred)
# plt.show()