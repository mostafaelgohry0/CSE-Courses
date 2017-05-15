import gui
import sqlite3


## create connection 
conn=sqlite3.connect('inventory.db');
c = conn.cursor()

c.execute("CREATE TABLE IF NOT EXISTS  table1(id INTEGER    PRIMARY KEY AUTOINCREMENT  ,name  TEXT,available REAL,cost  REAL,total_cost REAL)")

conn.commit()



def insert_fun():
        
    try:
        
        inputName=str(gui.nameText.text());
        inputAvailable=int(gui.availableText.text());
        inputCost=int(gui.costText.text());
        total_cost=inputAvailable*inputCost;
        
        # check if there is an item in the database in the same name 
        i=c.execute("select name  from table1 where name = ?",(inputName,))
        # fetchall return an list with exist item 
        item=i.fetchall();
        
        
        # in case no item  length of the list will be 0 
        if len(item)==0:
        
            c.execute("insert into table1 ( name ,available ,cost,total_cost) values(?,?,?,?)",(inputName,inputAvailable,inputCost,total_cost) )
            conn.commit()
            
            print  "insert done "
            # print message 
            gui.msg.setText("you inserted  " + inputName)
            gui.msg.exec_()
         
         
        else :
        
            print "item exist"
            #print message 
            gui.msg.setText( inputName + " is already inserted")
            gui.msg.exec_()
            

            
            
            
    #print item[0][0]
    #print item[0][1]
        
        '''
        c.execute("insert into table1 ( name ,available ,cost,total_cost) values(?,?,?,?)",(inputName,inputAvailable,inputCost,total_cost) )
        conn.commit()
        print  "insert done "
        '''
        
        
    except:
        
        print "error "
        gui.msg.setText(" error while insert  " + inputName)
        gui.msg.exec_()
        
        
        
        
        
def update_fun():
    
    try:
        
        inputName=str(gui.nameText.text());
        inputAvailable=int(gui.availableText.text());
        inputCost=int(gui.costText.text());
        total_cost=inputAvailable*inputCost;
        
        c.execute("update  table1 set  available=? , cost=?  , total_cost=? where name=? ",(inputAvailable ,inputCost,total_cost,inputName))
        conn.commit();
        
        print "update done "
        gui.msg.setText(inputName + "  updated   "  )
        gui.msg.exec_()
        
    except:
        
        gui.msg.setText(" error while update  " + inputName)
        gui.msg.exec_()
        
        print "erro update"
        



def delete_fun():
    
    try:
        inputName=str(gui.nameText.text());
       
        
        c.execute("delete from   table1   where name=? ",(inputName,))
        conn.commit();
        print "delete  done "
        
        gui.msg.setText(inputName + "  deleted  "  )
        gui.msg.exec_()
        
    except:
        
        print "erro delete"
        
        gui.msg.setText(" error while delete  " + inputName)
        gui.msg.exec_()
        
        

        
        
        
gui.exitBtn.clicked.connect(exit)
gui.insertBtn.clicked.connect(insert_fun)
gui.updateBtn.clicked.connect(update_fun)
gui.deleteBtn.clicked.connect(delete_fun)


# showing the main gui 
gui.mainWindow.show();
gui.myapp.exec_();


c.close()
conn.close()

