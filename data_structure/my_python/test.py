#!/usr/bin/python3
import requests #导入requests 模块
from bs4 import BeautifulSoup  #导入BeautifulSoup 模块
import os  #导入os模块

class BeautifulPicture():

    def __init__(self):  #类的初始化操作
        self.headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/22.0.1207.1 Safari/537.1'}  #给请求指定一个请求头来模拟chrome浏览器
        self.web_url = 'http://q.10jqka.com.cn/'  #要访问的网页地址
        self.folder_path = '/home/shuai/ilike/ilike/data_structure/my_python'  #设置图片要存放的文件目录

    def get_pic(self):
        print('开始网页get请求')
        r = self.request(self.web_url)
        print('开始获取所有a标签')
        all_a = BeautifulSoup(r.text, 'lxml').find('tbody')#, class_='m-table m-pager-table')  #获取网页中的class为cV68d的所有a标签
        #print(all_a.get_text())
        print('开始创建文件夹')
        self.mkdir(self.folder_path)  #创建文件夹
        print('开始切换文件夹')
        os.chdir(self.folder_path)   #切换路径至上面创建的文件夹

        print(type(all_a))
        print(all_a.name)
        print(type(all_a.find('tr')))
        print(all_a.find('tr').name)
        tr = all_a.find('tr')
        print(type(tr))
        print(tr.attrs)
        td = tr.find_all('td')
        for t in td:
            print(t.attrs)
            print(t.string)


        # i = 0
        # print(type(all_a))
        # for a in all_a: #循环每个标签，获取标签中图片的url并且进行网络请求，最后保存图片
        #     #b = a.thead
        #     i = i + 1
        #     if a.name != None :
        #         print(type(a))
        #         print(a.name)
        #         print(a.td)
        #         print(a.get_text())
        #         for b in a.find_all('a'):
        #             print(b.get('href'))



    def save_img(self, url, name): ##保存图片
        print('开始请求图片地址，过程会有点长...')
        img = self.request(url)
        file_name = name + '.jpg'
        print('开始保存图片')
        f = open(file_name, 'ab')
        f.write(img.content)
        print(file_name,'图片保存成功！')
        f.close()

    def request(self, url):  #返回网页的response
        r = requests.get(url, headers=self.headers)  # 像目标url地址发送get请求，返回一个response对象。有没有headers参数都可以。
        return r

    def mkdir(self, path):  ##这个函数创建文件夹
        path = path.strip()
        isExists = os.path.exists(path)
        if not isExists:
            print('创建名字叫做', path, '的文件夹')
            os.makedirs(path)
            print('创建成功！')
        else:
            print(path, '文件夹已经存在了，不再创建')

beauty = BeautifulPicture()  #创建类的实例
beauty.get_pic()  #执行类中的方法
