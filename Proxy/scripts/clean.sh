REFLECTOR_IP=192.168.25.19

sudo route del -host $REFLECTOR_IP reject
sudo rm -r ../proxy && rm -r ../blacklist.txt
