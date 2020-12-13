#!/usr/bin/python3
import requests #导入requests 模块
from bs4 import BeautifulSoup  #导入BeautifulSoup 模块
import os  #导入os模块

class BeautifulNews():

    def __init__(self):  #类的初始化操作
        self.headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/22.0.1207.1 Safari/537.1'}  #给请求指定一个请求头来模拟chrome浏览器
        self.web_url = 'https://news.sina.com.cn/roll/#pageid=153&lid=2509&k=&num=50&page=1'  #要访问的网页地址

    def get_news(self):
        print('开始网页get请求')
        r = self.request(self.web_url)
        print('开始获取所有a标签')
        all_a = BeautifulSoup(r.text, 'lxml').find('div')#, class_='d_list_txt')  #获取网页中的class为cV68d的所有a标签
        print(all_a.get_text())


    def request(self, url):  #返回网页的response
        r = requests.get(url, headers=self.headers)  # 像目标url地址发送get请求，返回一个response对象。有没有headers参数都可以。
        return r

beauty = BeautifulNews()
beauty.get_news()

