使用ssh方式（推荐）

1、在每次push 的时候，都要输入用户名和密码，是不是很麻烦？原因是使用了https方式 push，在git bash里边输入 git remote -v

$ git remote rm origin    //删除http
$ git remote add origin git@github.com:langsunny/stepyoyo.git   //添加shh,以我的git仓库为例
$ git push origin   //执行你的更改

再次执行 git remote -v 查看是否更新成功（对比第一次执行）

ssh-keygen -t rsa -C “seesaw@email.com” 
添加你的SSH公钥（email是你github注册账号的邮箱）

   
    第一次出现：Enter file in which to save the key (/root/.ssh/id_rsa): 直接按回车就行

    第二次出现：Enter passphrase (empty for no passphrase): 第一次输入公钥密码(推荐不用输入，直接回车，以便在clone、pull、push等不用输入公钥密码)

    第三次出现：Enter same passphrase again: 再次输入公钥密码

公钥创建成功，位置在你使用 git bush 的当前项目目录下(xx.pub)

公钥和私钥配对，接下来去C盘找你的私钥

私钥一般在你的用户文件夹的 .ssh下，打开xx.pub,复制内容，在github中创建ssh keys （没有私钥，百度）

接下来 push 就不需要密码了.Enjoy it!
