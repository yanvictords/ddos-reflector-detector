cd ../test
gcc dnsPackage.c udpServer.c -o s -pthread
sudo ./s
cd ../scripts
bash clean.sh
