#!/bin/bash
# root
# ABC
# uniview
# please enter 0 or "other"
# if  0 ----> 123456
# else (case) 



echo "ABC"
top -n 1 > /dev/null
echo "uniview" >/dev/null
read TYPE  #TYPE 判断是否5月9号之后的
echo "$TYPE"
if [ "$TYPE" = "0" ];then
    echo "[ YES ]" 
elif [ "$TYPE" != "0" ] ;then
    case $TYPE in
        100)
            echo "passwd:100"
            ;;
        133)
            echo "passwd:222"
            ;;
        *)
            echo "other command"
            ;;
    esac
    echo "[ NO ]"
fi

echo -e "\r"
ls
#export 找到
export PGPASSWORD="git"  
  
top -n 1 > /dev/null
echo "here"

clear
ps -ef
