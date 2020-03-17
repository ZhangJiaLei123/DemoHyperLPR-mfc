# [MFC] 基于HyperLPR的车牌识别

本项目是基于开源框架搭建的MFC车牌识别桌面Demo，只做学习和验证

> HyperLPR是开源中文车牌识别框架,[项目地址](https://github.com/zeusees/HyperLPR):https://github.com/zeusees/HyperLPR

## 首先来看最终效果

![效果](https://github.com/ZhangJiaLei123/Picture_bed/blob/master/MFC-OpenCV-Prj-%E8%BD%A6%E7%89%8C%E8%AF%86%E5%88%AB.png?raw=true)

## 环境
 1. 安装VS2017-MFC开发环境：[下载](blob:https://visualstudio.microsoft.com/91f06358-745f-4fd7-854d-f10c9529b4fe)
 1. 下载OpenCV3.3.0： [下载](https://nchc.dl.sourceforge.net/project/opencvlibrary/opencv-win/3.3.0/opencv-3.3.0-vc14.exe)、
 具体安装方法见教程[OpenCV&VS2017配置方法](https://blog.csdn.net/guojunxiu/article/details/79124005)

> 建议使用opencv330版本的，我尝试使用更高版本时，会有报错

 ## 运行
 1. 支持视频流车牌识别（支持MP4格式视频，其他格式未尝试）
 2. 支持单吐图片识别（支持jpg格式图片，其他格式未尝试）
 3. 支持自定义识别频率和播放速度
 1. 单独的识别结果预览
 1. 识别结果保存
 1. 可信度筛选

 ## TODO
 1. 使用GPU加速
 > 如果视频或图片较大，CUP的运算速度实在太慢，如果使用GPU加速，可能会对识别速度有一个提升，但目前暂时不做，待有空再研究