#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import kMeans

#加载iris数据集
iris = kMeans.loadDataSet("iris.data")

#下面对iris数据集整体分析
#调用kmeans函数
iris_cent, iris_result = kMeans.kmeans(iris, 3)
#结果展示
#获取SSE
SSE = iris_result.iloc[:,5].sum()
print("\nSSE：",SSE)
#打印簇质心
print("\niris centroids:\n")
print(iris_cent)
#打印处理后的数据集
print("\niris result set:\n")
print(iris_result)

#对不同k值进行测试
x = list(range(1,10))
y = []
for k in x:
    iris_cent, iris_result = kMeans.kmeans(iris,k)
    sse = iris_result.iloc[:,5].sum()
    y.append(sse)
plt.plot(x,y)
for x, y in zip(x, y):
    plt.text(x, y , '%.2f' % y, ha='center', va='bottom')
#加上标题和坐标轴标题
plt.title("the SSE of different k")
plt.xlabel("k")
plt.ylabel("SSE")
#结果展示
plt.show()

#下面对iris数据集两两分析
#创建零向量
ze = np.zeros(iris.shape[0]).reshape(-1,1)
#标签初始化为-1
ze[:] = -1
#加上标签
sepal = pd.concat([iris.iloc[:,:2], pd.DataFrame(ze)], axis=1, ignore_index=True)
petal = pd.concat([iris.iloc[:,2:4], pd.DataFrame(ze)], axis=1, ignore_index=True)
#调用kmeans函数
sepal_cent, sepal_result = kMeans.kmeans(sepal, 3)
petal_cent, petal_result = kMeans.kmeans(petal, 2)
#构建子图1
ax1 = plt.subplot(1,2,1)
plt.scatter(sepal_result.iloc[:,0], sepal_result.iloc[:,1], c=sepal_result.iloc[:,-1], marker='.')
plt.scatter(sepal_cent[:,0],sepal_cent[:,1], c='red', marker='x', s=100)
plt.title("sepal")
#构建子图2
ax2 = plt.subplot(1,2,2)
plt.scatter(petal_result.iloc[:,0], petal_result.iloc[:,1], c=petal_result.iloc[:,-1], marker='.')
plt.scatter(petal_cent[:,0],petal_cent[:,1], c='red', marker='x', s=100)
plt.title("petal")
#展示
plt.show()

#不同k值对iri数据集两两测试
ax3 = plt.subplot(1,2,1)
x1 = list(range(1,10))
y1 = []
for k in x1:
    sepal_cent, sepal_result = kMeans.kmeans(sepal, k)
    sse = sepal_result.iloc[:,3].sum()
    y1.append(sse)
plt.plot(x1,y1)
for x1, y1 in zip(x1, y1):
    plt.text(x1, y1 , '%.2f' % y1, ha='center', va='bottom')
plt.title("sepal")

ax4 = plt.subplot(1,2,2)
x2 = list(range(1,10))
y2 = []
for k in x2:
    petal_cent, petal_result = kMeans.kmeans(petal, k)
    sse = petal_result.iloc[:,3].sum()
    y2.append(sse)
plt.plot(x2,y2)
for x2, y2 in zip(x2, y2):
    plt.text(x2, y2 , '%.2f' % y2, ha='center', va='bottom')
plt.title("petal")

plt.show()