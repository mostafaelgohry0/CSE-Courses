
from PyQt4.QtCore import *    
from PyQt4.QtGui  import *

import sys



myapp = QApplication(sys.argv)  

mainWindow=QWidget();   # create the mainWindow 


mainWindow.setWindowIcon(QIcon('logo.png')) ;  # set the logo 

mainWindow.setWindowTitle("DB LAB")    




mainLable=QLabel(mainWindow)  #  for lable 
mainLable.setText(" <h1>Inventory  DB </h1> ")
mainLable.move(200,20)        #  set postion 







#  name 
nameLable=QLabel(mainWindow)
nameLable.setText("<h2>Name</h2>")
nameLable.move(100,100)

nameText=QLineEdit(mainWindow)
nameText.setGeometry(250,100,120,40)
nameText.setPlaceholderText("  your name")



# available
availableLable=QLabel(mainWindow)
availableLable.setText("<h2>Available</h2>")
availableLable.move(100,200)

availableText=QLineEdit(mainWindow)
availableText.setGeometry(250,200,120,40)
availableText.setPlaceholderText("  available item ")




# Cost
costLable=QLabel(mainWindow)
costLable.setText("<h2>Cost</h2>")
costLable.move(100,300)

costText=QLineEdit(mainWindow)
costText.setGeometry(250,300,120,40)
costText.setPlaceholderText("  cost")



############################################


#    buttons 

# insert
insertBtn=QPushButton("Insert ",mainWindow)
insertBtn.setGeometry(20,400,100,50)
insertBtn.setToolTip("Insert the data")




# update
updateBtn=QPushButton("Update ",mainWindow)
updateBtn.setGeometry(140,400,100,50)
updateBtn.setToolTip("update the data")



# Delete
deleteBtn=QPushButton("Delete",mainWindow)
deleteBtn.setGeometry(260,400,100,50)
deleteBtn.setToolTip("Delete  the data")





# exit
exitBtn=QPushButton("Exit ",mainWindow)
exitBtn.setGeometry(380,400,100,50)
exitBtn.setToolTip("click to exit")







# message 
msg = QMessageBox()
msg.setIcon(QMessageBox.Information)
