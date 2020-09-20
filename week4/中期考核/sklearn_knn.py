#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier #KNN
from sklearn.model_selection import train_test_split #数据分割模块

#加载数据集
iris_test = datasets.load_iris()
#获取数据和标签
iris_test_data = iris_test.data
iris_test_target = iris_test.target
#分割训练集和测试集
a = 0.2 #比例
x_train,x_test,y_train,y_test = train_test_split(iris_test_data,iris_test_target,test_size=a)

#下面测试一个k值
#设置k的大小
k = 6
#调用KNN
knn = KNeighborsClassifier(n_neighbors=k)
knn.fit(x_train,y_train)
#得到预测分类结果
result = knn.predict(x_test)
print("\nknnClassify：\n")
print(result)
#计算准确率
correct = 0
for item1,item2 in zip(result,y_test):
    if item1 == item2:
        correct += 1
accuracy = (correct / float(len(y_test)))
#打印准确率
print("\n")
print("Accuracy：%.2f%%" % (accuracy*100.0))
print("\n")

#下面测试多个k值
x = list(range(1,10))
y = []
for k in x:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(x_train,y_train)
    result = knn.predict(x_test)
    #计算准确率
    correct = 0
    for item1,item2 in zip(result,y_test):
        if item1 == item2:
            correct += 1
    accuracy = (correct / float(len(y_test)))
    #添加到列表中
    y.append(accuracy)
#画折线图
plt.plot(x,y)
#增加数值
for x, y in zip(x, y):
    plt.text(x, y , '%.2f' % y, ha='center', va='bottom')
#加上标题和坐标轴标题
plt.title("the accuracy of different k")
plt.xlabel("k")
plt.ylabel("accuracy")
#结果展示
plt.show()