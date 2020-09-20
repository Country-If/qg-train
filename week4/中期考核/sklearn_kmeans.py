#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.cluster import KMeans

#��������
iris = pd.read_csv("iris.data", header=None)

#�����iris���ݼ��������
#����kmeans����
model = KMeans(n_clusters=3).fit(iris.iloc[:,:-1])
#���չʾ
#��ȡSSE
sse = model.inertia_
print("\nSSE��",sse)
#��ӡ������
print("\niris centroids:\n")
print(model.cluster_centers_)
print("\n")

#�Բ�ͬkֵ���в���
x = list(range(1,10))
y = []
for k in x:
    sse = KMeans(n_clusters=k).fit(iris.iloc[:,:-1]).inertia_
    y.append(sse)
plt.plot(x,y)
for x, y in zip(x, y):
    plt.text(x, y , '%.2f' % y, ha='center', va='bottom')
#���ϱ�������������
plt.title("the SSE of different k")
plt.xlabel("k")
plt.ylabel("SSE")
#���չʾ
plt.show()

#�����iris���ݼ���������
#����������
ze = np.zeros(iris.shape[0]).reshape(-1,1)
#��ǩ��ʼ��Ϊ-1
ze[:] = -1
#���ϱ�ǩ
sepal = pd.concat([iris.iloc[:,:2], pd.DataFrame(ze)], axis=1, ignore_index=True)
petal = pd.concat([iris.iloc[:,2:4], pd.DataFrame(ze)], axis=1, ignore_index=True)
#����kmeans����
sepal_cent = KMeans(n_clusters=3).fit(sepal).cluster_centers_
sepal_labels = KMeans(n_clusters=3).fit(sepal).labels_
petal_cent = KMeans(n_clusters=2).fit(petal).cluster_centers_
petal_labels = KMeans(n_clusters=2).fit(petal).labels_
#������ͼ1
ax1 = plt.subplot(1,2,1)
plt.scatter(sepal.iloc[:,0], sepal.iloc[:,1], c=sepal_labels, marker='.')
plt.scatter(sepal_cent[:,0],sepal_cent[:,1], c='red', marker='x', s=100)
plt.title("sepal")
#������ͼ2
ax2 = plt.subplot(1,2,2)
plt.scatter(petal.iloc[:,0], petal.iloc[:,1], c=petal_labels, marker='.')
plt.scatter(petal_cent[:,0],petal_cent[:,1], c='red', marker='x', s=100)
plt.title("petal")
#չʾ
plt.show()

#��ͬkֵ��iri���ݼ���������
ax3 = plt.subplot(1,2,1)
x1 = list(range(1,10))
y1 = []
for k in x1:
    sse = KMeans(n_clusters=k).fit(sepal).inertia_
    y1.append(sse)
plt.plot(x1,y1)
for x1, y1 in zip(x1, y1):
    plt.text(x1, y1 , '%.2f' % y1, ha='center', va='bottom')
plt.title("sepal")

ax4 = plt.subplot(1,2,2)
x2 = list(range(1,10))
y2 = []
for k in x2:
    sse = KMeans(n_clusters=k).fit(petal).inertia_
    y2.append(sse)
plt.plot(x2,y2)
for x2, y2 in zip(x2, y2):
    plt.text(x2, y2 , '%.2f' % y2, ha='center', va='bottom')
plt.title("petal")
#���չʾ
plt.show()