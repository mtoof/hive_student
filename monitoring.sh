#! /bin/bash

arch=$(uname -a)
pcpu=$(nproc --all)
vcpu=$(cat /proc/cpuinfo | grep processor | wc -l)
memused=$(free -m | grep Mem | awk '{printf("%.f/%.fMB (%.2f%%)", $3,$2,$3/$2 * 100.0)}')
disku=$(df -Bm --total |grep total |awk '{printf("%d/", $3)}')$(df -h --total | grep total | awk '{printf("%.fGb (%s)", $2, $5)}')
cpu=$(mpstat | grep all | awk '{printf("%.1f%%\n", 100-$13)}')
lastboot=$(who -b | awk '{print $3" " $4}')
lvm=$(if  cat /etc/fstab | grep 'root' | grep -q /dev/mapper/ ; then echo "yes"; fi)
tcp=$(ss -s | awk '/TCP:/ {printf("%d\n", $4)}')
users=$(who -u | awk '{print $1}' | uniq | wc -l)
ip=$(hostname -I | awk '{print "IP " $1}')
mac=$(ip a | awk '/link\/ether/ {printf("(%s)", $2)}')
sudolines=$(journalctl _COMM=sudo | grep "COMMAND" | wc -l)
wall "
        #Architecture: $arch
        #CPU physical : $pcpu
        #vCPU : $vcpu
        #Memory Usage: $memused
        #Disk Usage: $disku
        #CPU load: $cpu
        #Last boot: $lastboot
        #LVM use: $lvm
        #Connections TCP : $tcp ESTABLISHED
        #User log: $users
        #Network: $ip $mac
        #Sudo : $sudolines cmd"
