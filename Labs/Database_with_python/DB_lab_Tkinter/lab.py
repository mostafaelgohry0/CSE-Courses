import Tkinter
from Tkinter  import *
import sqlite3

conn = sqlite3.connect('db.db')
c = conn.cursor()

### create the database
c.execute("CREATE TABLE IF NOT EXISTS  t(id INTEGER    PRIMARY KEY AUTOINCREMENT  ,name  TEXT,available REAL,cost  REAL,total_cost REAL)")

root =Tk()
root.geometry("400x200+200+100")
root.title("DB Lab")


Tops = Frame(root, width=300 , height =100)
Tops.pack(side = TOP)

f1 = Frame(root, width=300 ,height = 200)
f1.pack(side = LEFT )

f2 = Frame(root, width=200 ,height = 200)
f2.pack(side = RIGHT)

lbl = Label(Tops, font =('arial',30,'bold'), text ="DB Lab", anchor = 'w')
lbl.grid(row=0,column = 0)

lbl1 = Label(f1, font =('arial',10,'bold'), text ="name ", anchor = 'w')
lbl1.grid(row=0,column = 0)
lbl2 = Label(f1, font =('arial',10,'bold'), text ="available", anchor = 'w')
lbl2.grid(row=1,column = 0)
lbl3 = Label(f1, font =('arial',10,'bold'), text ="cost", anchor = 'w')
lbl3.grid(row=2,column = 0)

txt1 = Entry(f1,font =('arial',10,'bold'))
txt1.grid(row=0, column = 1)

txt2 = Entry(f1,font =('arial',10,'bold'))
txt2.grid(row=1, column = 1)

txt3 = Entry(f1,font =('arial',10,'bold'))
txt3.grid(row=2, column = 1)
conn.commit()

def insert_cal():    
    
    try:
        
        x1=int(txt2.get())
        x2=int(txt3.get())
        n=str(txt1.get())
    

        total = x1*x2
  
        c.execute("INSERT INTO t(name,available,cost,total_cost) VALUES(?,?,?,?)",(n,x1,x2,total))
    
        conn.commit()
        print " inserted "
       
    except:
         
        print("Failed to insert")





def update_cal():    
    try:
        
        
        x1=int(txt2.get())
        x2=int(txt3.get())
        n=str(txt1.get())

        total = x1*x2
        
        c.execute("UPDATE t SET available = ?, cost= ?, total_cost=?  WHERE name = ?",(x1,x2,total,n))
        conn.commit()
        print " updated "
        
    except:
        
        print("Failed to update")
        
        
        

def delete_cal():    
    try:
        n=str(txt1.get())
        
        c.execute("DELETE FROM t WHERE name =? ",(n,))
        conn.commit()
        print "deleted"
    except:
       
        print("Failed to delete")







    
b1=Button(f2,command=insert_cal,text="Insert",width = 10).grid(row=0)
b2=Button(f2,command=update_cal,text="Update",width = 10).grid(row=1)
b3=Button(f2,command=delete_cal,text="Delete",width = 10).grid(row=2)

    
root.mainloop()
c.close()
conn.close()
