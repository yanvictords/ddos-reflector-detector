DEFAULT_ROUTER=192.168.25.1
PROXY_IP=192.168.25.13

route add default gw $DEFAULT_ROUTER
route del default gw $PROXY_IP

clear ../r && clear ../c
