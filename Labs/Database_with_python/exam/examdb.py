import Tkinter
from Tkinter  import *
import sqlite3

conn = sqlite3.connect('exam.db')
c = conn.cursor()

### create the database
c.execute("CREATE TABLE IF NOT EXISTS  table1( name text   PRIMARY KEY   ,password TEXT )")

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
lbl2 = Label(f1, font =('arial',10,'bold'), text ="password", anchor = 'w')
lbl2.grid(row=1,column = 0)


txt1 = Entry(f1,font =('arial',10,'bold'))
txt1.grid(row=0, column = 1)

txt2 = Entry(f1,font =('arial',10,'bold'))
txt2.grid(row=1, column = 1)


conn.commit()

def login_cal():    
    
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




def test():
    
    input_name=str(txt1.get())
    input_password=str(txt2.get())
    
    p=c.execute("select password from table1")
    all_passwords=p.fetchall()
    print all_passwords 
    
    passwords_length=len(all_passwords);
    print passwords_length;
    
    
    #print str(all_passwords[3][0])
    
    for i in range (0,passwords_length):
        
        if input_password == all_passwords[i][0]:
            
        
            print "true"
            break;
            
        else :
            
            print "no"
        
    



    
b1=Button(f2,command=test,text="Login",width = 10).grid(row=3)

    
root.mainloop()
c.close()
conn.close()
