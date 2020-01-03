# Safety home automation

This directory contains informations and code to create a video surveillance, alarm and information system in case of home intrusion.

## How it's work
  
![alt text](SysML/SysML_1_6_Block_Definition_Diagram.png)  
  
## Hardware

The hardware use to make this system is as follow :
- One Arduino (at least Uno),  
  
![alt text](Images/Arduino.jpg)
  
- Ultrasonic sensor to determine the distance, 
   
![alt text](Images/Ultrasonic.jpg)
  
- Speaker,  
  
![alt text](Images/Speaker.jpg)
  
- One Raspberry Pi (at least 3 Model B) to manage the system,  
- One Raspberry Pi for each camera,  
  
![alt text](Images/Raspberry.jpg)
  
- Raspberry Pi compatible cameras 
     
![alt text](Images/Camera.jpg)

## Software

**Operating System**

Each Raspberry Pi must have Raspbian installed. You can choose an other OS but Raspbian is advisable.

### Python
This code is to automatically send a message when a intruder is detected
```sh
$ pip install fbchat
```
```sh
# -*- coding: UTF-8 -*-

from fbchat import Client
from fbchat.models import *

client = Client("<email>", "<password>")

print("Own id: {}".format(client.uid))

client.send(Message(text="Hi me!"), thread_id=client.uid, thread_type=ThreadType.USER)

client.logout()
```
### Apache
Update Raspbian
```sh
$ sudo apt update
$ sudo apt upgrade
$ sudo apt update
```
Install apache
```sh
$ sudo apt install apache2
```
Directory will be readable
```sh
$ sudo chown -R pi:www-data /var/www/html/
```
Directory will be readable, writable and executabl
```sh
$ sudo chmod -R 770 /var/www/html/
```
Get the home page
```sh
$ wget -O apache.html http://127.0.0.1
```
If it's done, you can see "it's work" on the code
```sh
$ cat ./apache.html
```
### PHP
Install PHP
```sh
$ sudo apt install php php-mbstring
```
Delete /var/www/index/index.html 
```sh
$ sudo rm /var/www/html/index.html
```
Create index.php with phpinfo()
```sh
$ echo "<?php phpinfo(); ?>" > /var/www/html/index.php
```
 
