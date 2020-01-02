# Safety home automation

This directory contains informations and code to create a video surveillance, alarm and information system in case of home intrusion.

## Hardware

The hardware use to make this system is as follow :
- One Arduino (at least Uno),  
![alt text](Images/Arduino.jpg)
- Ultrasonic sensor to determine the distance,  
![alt text](Images/Ultrasonic.png)
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

### Arduino
This code is to manage all the sensors linked to the arduino (Distance sensor and alarm)
```sh
//Arduino code here
```
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

### PHP
This code is to monitor the room in live
```sh
<!DOCTYPE html>
<html lang="fr">

<head>
	<meta charset="utf-8">
	<title>Nautilus</title>
	<meta name="viewport" content="width=device-width,initial-scale=1" />
	<link href="A-style.css" rel="stylesheet" media="all" type="text/css"> 
</head>

<body class="pi-dashboard">

	<H1>Tableau de bord maison 192.168.1.104 (nautilus)</h1>
	 
	<section class="video-surveillance">

		<img name="Galaxy-Tab" class="stream" src="http://192.168.1.104:8082/?action=stream" width="600" height="450" alt="Live Feed" title="Galaxy Tab GT-P6210" />

		<img name="Foscam-FI8905W" class="stream" src= "http://192.168.1.104:8081/?action=stream" width="600" height="450" title="Foscam FI8905W"/>
		
	</section>
	
	<section class="capteurs">

		<h3>Autres informations</h3>
		<p>A venir...</p>
		
	</section>
 
</body>
</html>
```
###CSS
```sh
body {
 padding: 0.3%;
 font-family: Georgia, "Times New Roman",
 Times, serif;
 color: purple;
 background-color: #d8da3d ;
 width: 95%;
 text-align: center;
}

section.video-surveillance {
 display: flex; /* or inline-flex */
 justify-content: space-around;
 display: inline-block;
}
 
h1 {
 font-family: Helvetica, Geneva, Arial,
 SunSans-Regular, sans-serif ;
 margin-top: 1em;
}

img.stream {
 padding: 1%;
}


@media only screen and (min-width: 800px){
 
 section.video-surveillance {
 flex-direction: row ;
 }
 
 img.stream {
 max-width: 45% ;
 height: auto;
 }

}

@media only screen and (max-width: 800px){
 
 section.video-surveillance {
 flex-direction: column ;
 }
 
 img.stream {
 max-width: 95%;
 height: auto;
 }
 
}
```
 
