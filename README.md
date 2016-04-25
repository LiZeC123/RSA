基于RSA算法的加密解密系统
===================================

##功能说明
这是一个关于RSA加密算法的简单程序，在最近的版本中，可以进行英文文本的加密，解密和密钥对的生成。*密钥长度较低*，仅作为对RSA加密算法的探究。



##安装说明
		linux下在对应的文件夹下执行 make ，windows下请参考Makefile自行寻找编译器编译。



##使用说明
###一 加密
	将需要加密的文件，放在source.txt中，程序启动后，按照提示输入指令，选择加密功能。
	之后按照提示输入公钥即可完成加密。加密后的密文将存放在result.txt中。

###二 解密
	解密过程与加密过程相反，操作类似。

###三 生成密钥对
	程序启动后，按照提示输入指令，选择生成密钥对功能，即可随机生成一对密钥，同时在程序所在文件夹中，将产生
	Pub_key,txt和Pri_key.txt文件，其中包含按照时间排列的密钥对记录。
    


##错误处理
如果文件在运行过程中产生一些*可以预料的*错误，将会在程序所在文件夹中生成Error.txt文件。



##其他文件
在程序初次运行时，会产生primer_number.txt和configuration,txt，其中包含生成密钥对所需要的素数表以及程序的配置信息。


##配置说明
configuration.txt中包含了程序运行过程中需要的参数，目前仅包含素数表中素数的总数。目前*请不要修改*其中的参数，否则会导致程序异常。

