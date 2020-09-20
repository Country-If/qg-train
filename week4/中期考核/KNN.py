#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

#读取文件
def loadDataSet(fileName):
    dataset = pd.read_csv(fileName, header=None)
    #返回dataframe
    return dataset

#从数据集中根据比例随机抽取数据集得到新数据集
def RandSet(dataset, x):
    #抽取说明：frac：抽取比例，replace：是否为有放回取样，random_state=None：取得数据不重复，axis=0：抽取行
    randSet = dataset.sample(frac=x, replace=False, random_state=None, axis=0)
    #行索引重新调整
    randSet.index = range(randSet.shape[0])
    #数据归一化处理
    randSet = normalSet(randSet)
    #返回dataframe
    return randSet

#计算两个数据点之间的欧式距离
def distEclud(arrA, arrB):
    d = arrA - arrB
    dist = np.sum(np.power(d, 2), axis=1)
    return dist**0.5

#knn算法
def knnPredict(testSet, trainset, k):
    #获取标签
    labels = trainset.iloc[:,4].values
    #获取行m、列n
    m1, n1 = trainset.shape #训练集
    m2, n2 = testSet.shape #测试集
    #初始化存放距离的容器dist
    dist = np.zeros((m2,m1))
    dist[:,:] = np.inf
    #计算测试集中各点到训练集中所有点的距离
    for i in range(m2): #对测试集中每一行
        for _ in range(m1): #对训练集中每一行
            dist[i,:] = distEclud(testSet.iloc[i,:n2-1].values, trainset.iloc[:,:n1-1].values)
    #给行贴上标签
    dist = pd.DataFrame(dist, columns=labels)
    #对每一行统计预测结果
    result = [] #创建list存放最终结果
    for i in range(m2):
        #对每一行升序排序，选取前k个点
        dr = dist.sort_values(by=i,axis=1).iloc[i,:k]
        #将dr改成字典形式，统计结果
        re = pd.DataFrame({'labels':dr.index, 'dist':dr.values}).loc[:,'labels'].value_counts()
        #re的第一个元素为统计数量最多的点，将结果存入result
        result.append(re.index[0])
    #返回result(list)
    return result

#计算准确率  
def get_Accuracy(testSet,result):
    correct = 0
    for i in range(len(testSet)):
        if testSet.iloc[i,-1] == result[i]:
            correct += 1
    accuracy = (correct / float(len(testSet)))
    return accuracy

#打印准确率
def print_Accuracy(testSet,result):
    accuracy = get_Accuracy(testSet,result) * 100.0
    print("Accuracy：%.2f%%" % accuracy)

#数据归一化
def normalSet(dataset):
    minDf = dataset.iloc[:,:-1].min()
    maxDf = dataset.iloc[:,:-1].max()
    normSet = (dataset.iloc[:,:-1] - minDf) / (maxDf - minDf)
    #贴上标签
    normSet = pd.concat([normSet,dataset.iloc[:,-1]], axis=1, ignore_index=True)
    #返回dataframe
    return normSet
