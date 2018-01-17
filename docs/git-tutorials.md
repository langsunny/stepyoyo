一. 使用ssh方式push（推荐）

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


二 进阶技巧
 1. 实际开发中，我们经常想看到前几次提交了啥，或者说想直接回退到某次提交，那么git 能够很好的实现你的需求，我们把test.txt多提交几次，然后使用git log命令，可以查看提交的历史和每次提交的内容更改。

那么如果你对最近一次提交不满意，怎么回退到上次提交或者以前的提交呢，那么得使用git reset --hard +历史版本的id（commit后面的一段hash码）命令。
 2. 文件移除

移除文件分为两种情况，一种是直接从git仓库，缓存区，工作目录中全部删除，另外一种就是从git仓库，缓存区中删除，但是依旧保留在工作目录中。
a.保留在工作目录中：git rm --cached，这样的话文件将会出现在Untracked files里面，因为他只存在与工作目录中。
git rm --cached.png

b.直接从工作目录中删除：git rm，为了这个命令的展示，我又将m.txt提交到了仓库中。
git rm.png

如果删除之前修改过并且已经放到暂存区域的话，则必须要用强制删除选项 -f，或者先commit再删除。



