#coding=gbk

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

#读取文件
def loadDataSet(fileName):
    dataset = pd.read_csv(fileName, header=None)
    #返回dataframe
    return dataset

#计算两个数据点之间的欧式距离的平方
def distEclud(arrA, arrB):
    d = arrA - arrB
    dist = np.sum(np.power(d, 2), axis=1)
    return dist

#随机生成k个质心
def randCent(dataset, k): #参数为ndarray
    n = dataset.shape[1] #数据的列数（除掉最后的标签）
    data_min = dataset.iloc[:, :n-1].min() #求最小值
    data_max = dataset.iloc[:, :n-1].max() #求最大值
    #生成质心，k行(n-1)列
    data_cent = np.random.uniform(data_min,data_max,(k, n-1)) #uniform用于生成给定范围的随机数
    #返回ndarray
    return data_cent

#kmeans算法
def kmeans(dataset, k, distmeans=distEclud, createcent=randCent):
    m, n = dataset.shape # m：行，n：列
    centroids = createcent(dataset, k) #随机生成k个质心
    #创建容器clusterAssment：第一列存放点到质心最小距离的平方(SSE)，第二列存放本次计算后所归属的簇，第三列存放上一次计算后所归属的簇
    clusterAssment = np.zeros((m,3)) #初始化容器clusterAssment
    clusterAssment[:, 0] = np.inf #距离初始化为无穷
    clusterAssment[:,1:3] = -1 #后两列初始化为-1
    #将cluster拼接到dataset之后
    result_set = pd.concat([dataset, pd.DataFrame(clusterAssment)], axis=1, ignore_index = True)
    clusterChanged = True
    while clusterChanged:
        clusterChanged = False
        for i in range(m): #对行进行迭代
            #计算每个点到各质心的距离(平方)
            dist = distmeans(dataset.iloc[i, :n-1].values, centroids) #values将series转换为ndarray
            #找到最小值并存入第n列
            result_set.iloc[i, n] = dist.min()
            #将最近的质心的编号存入第n+1列
            result_set.iloc[i, n+1] = np.where(dist == dist.min())[0]
        #判断最后两列是否完全相等
        clusterChanged = not (result_set.iloc[:, -1] == result_set.iloc[:, -2]).all() #all判断全部是否相等
        if clusterChanged:
            #对本次计算后的簇分组后求均值
            cent_df = result_set.groupby(n+1).mean()
            #质心更新
            centroids = cent_df.iloc[:,:n-1].values
            #将新的质心更新到最后一列
            result_set.iloc[:, -1] = result_set.iloc[:, -2]
    #返回最终得到的质心和数据集
    return centroids, result_set
