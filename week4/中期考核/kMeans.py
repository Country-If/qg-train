#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

#��ȡ�ļ�
def loadDataSet(fileName):
    dataset = pd.read_csv(fileName, header=None)
    #����dataframe
    return dataset

#�����������ݵ�֮���ŷʽ�����ƽ��
def distEclud(arrA, arrB):
    d = arrA - arrB
    dist = np.sum(np.power(d, 2), axis=1)
    return dist

#�������k������
def randCent(dataset, k): #����Ϊndarray
    n = dataset.shape[1] #���ݵ��������������ı�ǩ��
    data_min = dataset.iloc[:, :n-1].min() #����Сֵ
    data_max = dataset.iloc[:, :n-1].max() #�����ֵ
    #�������ģ�k��(n-1)��
    data_cent = np.random.uniform(data_min,data_max,(k, n-1)) #uniform�������ɸ�����Χ�������
    #����ndarray
    return data_cent

#kmeans�㷨
def kmeans(dataset, k, distmeans=distEclud, createcent=randCent):
    m, n = dataset.shape # m���У�n����
    centroids = createcent(dataset, k) #�������k������
    #��������clusterAssment����һ�д�ŵ㵽������С�����ƽ��(SSE)���ڶ��д�ű��μ�����������Ĵأ������д����һ�μ�����������Ĵ�
    clusterAssment = np.zeros((m,3)) #��ʼ������clusterAssment
    clusterAssment[:, 0] = np.inf #�����ʼ��Ϊ����
    clusterAssment[:,1:3] = -1 #�����г�ʼ��Ϊ-1
    #��clusterƴ�ӵ�dataset֮��
    result_set = pd.concat([dataset, pd.DataFrame(clusterAssment)], axis=1, ignore_index = True)
    clusterChanged = True
    while clusterChanged:
        clusterChanged = False
        for i in range(m): #���н��е���
            #����ÿ���㵽�����ĵľ���(ƽ��)
            dist = distmeans(dataset.iloc[i, :n-1].values, centroids) #values��seriesת��Ϊndarray
            #�ҵ���Сֵ�������n��
            result_set.iloc[i, n] = dist.min()
            #����������ĵı�Ŵ����n+1��
            result_set.iloc[i, n+1] = np.where(dist == dist.min())[0]
        #�ж���������Ƿ���ȫ���
        clusterChanged = not (result_set.iloc[:, -1] == result_set.iloc[:, -2]).all() #all�ж�ȫ���Ƿ����
        if clusterChanged:
            #�Ա��μ����Ĵط�������ֵ
            cent_df = result_set.groupby(n+1).mean()
            #���ĸ���
            centroids = cent_df.iloc[:,:n-1].values
            #���µ����ĸ��µ����һ��
            result_set.iloc[:, -1] = result_set.iloc[:, -2]
    #�������յõ������ĺ����ݼ�
    return centroids, result_set
