#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import KNN

#����iris���ݼ�
iris = KNN.loadDataSet("iris.data")
#���Լ���ѵ��������
x = 0.2
y = 0.8
#���ز��Լ���ѵ����
testset = KNN.RandSet(iris, x)
trainset = KNN.RandSet(iris, y)

#�������һ��kֵ
#����k�Ĵ�С
k = 6
#knn�õ�Ԥ����
result = KNN.knnPredict(testset,trainset,k)
#��ӡ���
print("\nknnClassify��\n")
print(result)
#��ӡ׼ȷ��
print("\n")
KNN.print_Accuracy(testset,result)
print("\n")

#������Զ��kֵ
x = list(range(1,10))
y = []
for k in x:
    #knnԤ��õ����
    result = KNN.knnPredict(testset,trainset,k)
    #����׼ȷ��
    accuracy = KNN.get_Accuracy(testset,result)
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