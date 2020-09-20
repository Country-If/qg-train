#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

#��ȡ�ļ�
def loadDataSet(fileName):
    dataset = pd.read_csv(fileName, header=None)
    #����dataframe
    return dataset

#�����ݼ��и��ݱ��������ȡ���ݼ��õ������ݼ�
def RandSet(dataset, x):
    #��ȡ˵����frac����ȡ������replace���Ƿ�Ϊ�зŻ�ȡ����random_state=None��ȡ�����ݲ��ظ���axis=0����ȡ��
    randSet = dataset.sample(frac=x, replace=False, random_state=None, axis=0)
    #���������µ���
    randSet.index = range(randSet.shape[0])
    #���ݹ�һ������
    randSet = normalSet(randSet)
    #����dataframe
    return randSet

#�����������ݵ�֮���ŷʽ����
def distEclud(arrA, arrB):
    d = arrA - arrB
    dist = np.sum(np.power(d, 2), axis=1)
    return dist**0.5

#knn�㷨
def knnPredict(testSet, trainset, k):
    #��ȡ��ǩ
    labels = trainset.iloc[:,4].values
    #��ȡ��m����n
    m1, n1 = trainset.shape #ѵ����
    m2, n2 = testSet.shape #���Լ�
    #��ʼ����ž��������dist
    dist = np.zeros((m2,m1))
    dist[:,:] = np.inf
    #������Լ��и��㵽ѵ���������е�ľ���
    for i in range(m2): #�Բ��Լ���ÿһ��
        for _ in range(m1): #��ѵ������ÿһ��
            dist[i,:] = distEclud(testSet.iloc[i,:n2-1].values, trainset.iloc[:,:n1-1].values)
    #�������ϱ�ǩ
    dist = pd.DataFrame(dist, columns=labels)
    #��ÿһ��ͳ��Ԥ����
    result = [] #����list������ս��
    for i in range(m2):
        #��ÿһ����������ѡȡǰk����
        dr = dist.sort_values(by=i,axis=1).iloc[i,:k]
        #��dr�ĳ��ֵ���ʽ��ͳ�ƽ��
        re = pd.DataFrame({'labels':dr.index, 'dist':dr.values}).loc[:,'labels'].value_counts()
        #re�ĵ�һ��Ԫ��Ϊͳ���������ĵ㣬���������result
        result.append(re.index[0])
    #����result(list)
    return result

#����׼ȷ��  
def get_Accuracy(testSet,result):
    correct = 0
    for i in range(len(testSet)):
        if testSet.iloc[i,-1] == result[i]:
            correct += 1
    accuracy = (correct / float(len(testSet)))
    return accuracy

#��ӡ׼ȷ��
def print_Accuracy(testSet,result):
    accuracy = get_Accuracy(testSet,result) * 100.0
    print("Accuracy��%.2f%%" % accuracy)

#���ݹ�һ��
def normalSet(dataset):
    minDf = dataset.iloc[:,:-1].min()
    maxDf = dataset.iloc[:,:-1].max()
    normSet = (dataset.iloc[:,:-1] - minDf) / (maxDf - minDf)
    #���ϱ�ǩ
    normSet = pd.concat([normSet,dataset.iloc[:,-1]], axis=1, ignore_index=True)
    #����dataframe
    return normSet
