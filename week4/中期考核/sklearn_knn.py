#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier #KNN
from sklearn.model_selection import train_test_split #���ݷָ�ģ��

#�������ݼ�
iris_test = datasets.load_iris()
#��ȡ���ݺͱ�ǩ
iris_test_data = iris_test.data
iris_test_target = iris_test.target
#�ָ�ѵ�����Ͳ��Լ�
a = 0.2 #����
x_train,x_test,y_train,y_test = train_test_split(iris_test_data,iris_test_target,test_size=a)

#�������һ��kֵ
#����k�Ĵ�С
k = 6
#����KNN
knn = KNeighborsClassifier(n_neighbors=k)
knn.fit(x_train,y_train)
#�õ�Ԥ�������
result = knn.predict(x_test)
print("\nknnClassify��\n")
print(result)
#����׼ȷ��
correct = 0
for item1,item2 in zip(result,y_test):
    if item1 == item2:
        correct += 1
accuracy = (correct / float(len(y_test)))
#��ӡ׼ȷ��
print("\n")
print("Accuracy��%.2f%%" % (accuracy*100.0))
print("\n")

#������Զ��kֵ
x = list(range(1,10))
y = []
for k in x:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(x_train,y_train)
    result = knn.predict(x_test)
    #����׼ȷ��
    correct = 0
    for item1,item2 in zip(result,y_test):
        if item1 == item2:
            correct += 1
    accuracy = (correct / float(len(y_test)))
    #��ӵ��б���
    y.append(accuracy)
#������ͼ
plt.plot(x,y)
#������ֵ
for x, y in zip(x, y):
    plt.text(x, y , '%.2f' % y, ha='center', va='bottom')
#���ϱ�������������
plt.title("the accuracy of different k")
plt.xlabel("k")
plt.ylabel("accuracy")
#���չʾ
plt.show()