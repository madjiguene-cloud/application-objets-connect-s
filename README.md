# application-objets-connect-s
application objets connectés de boudra et diedhiou
Ci dessous il y a les différentes lignes de commandes pour installer nodered et la base de donnée mariadb,

tous les autres procédure sont décris dans le rapport.
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
