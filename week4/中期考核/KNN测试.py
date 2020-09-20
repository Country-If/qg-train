#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import KNN

#加载iris数据集
iris = KNN.loadDataSet("iris.data")
#测试集和训练集比例
x = 0.2
y = 0.8
#加载测试集和训练集
testset = KNN.RandSet(iris, x)
trainset = KNN.RandSet(iris, y)

#下面测试一个k值
#设置k的大小
k = 6
#knn得到预测结果
result = KNN.knnPredict(testset,trainset,k)
#打印结果
print("\nknnClassify：\n")
print(result)
#打印准确率
print("\n")
KNN.print_Accuracy(testset,result)
print("\n")

#下面测试多个k值
x = list(range(1,10))
y = []
for k in x:
    #knn预测得到结果
    result = KNN.knnPredict(testset,trainset,k)
    #计算准确率
    accuracy = KNN.get_Accuracy(testset,result)
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