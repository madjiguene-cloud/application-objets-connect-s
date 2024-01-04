# application-objets-connect-s
application objets connectés de boudra et diedhiou
Ci dessous il y a les différentes lignes de commandes pour installer nodered et la base de donnée mariadb,
tous les autres procédure sont décris dans le rapport.
Le nodered_serveur décrit la configuration de nodered pour le medecin.
Le nodered_raspberry décrit la configuration de nodered pour le patients.

Le fichier EGG_code nous permet de mesurer le rythme cardiaque (Heart Rate - HR) et la variabilité du rythme cardiaque (Heart Rate Variability - HRV) à partir d'un capteur d'ECG.
Le fichier Simul_freq permet de générer un signal analogique simulant les variations du signal électrique du cœur.
Le fichier Send_freq nous de lire, traiter les données, calculer la fréquence cardiaque, et les transmettre au TTN pour les professionnels de la santé (serveurs) et aux ports série pour la Raspberry Pi, destinée aux patients.

ˋˋ Installation node-red :

curl -sl https://deb.nodesource.com/setup_14.x |
sudo -E bash - 
sudo apt update sudo apt install nodejs
npm -v
apt install npm
sudo npm install -g --unsafe-perm node-red

Installer les modules necessaire au deploiement node-red :

option -> manage palette -> installer :
     Mysql
     Moment
     Dashboard 
     Serial 
     Ui-Table

Apres avoir tout installer importer le fichier flow.json
Configurer mysql pour le connecter a votre base de donnée

Base de donnee     
Installer mariadb ou mysql :

Sudo apt-get install mariadb-server mariadb-client 

Créer Base de donnees ecg_data :
   CREATE DATABASE ecg_data
Créer les 2 tables freq et freq_sup :
   CREATE TABLE freq ( Date DATATIME, BPM INT )
   CREATE TABLE freq_sup ( Date DATATIME, BPM INT )

Creer utilisateur et lui donnee les droits : 
  CREATE USER 'nouveau_utilisateur'@'localhost' IDENTIFIED BY 'mot_de_passe';

  GRANT ALL PRIVILEGES ON * . * TO 'nouveau_utilisateur'@'localhost';

  FLUSH PRIVILEGES

ˋˋ
