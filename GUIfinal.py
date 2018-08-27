import socket
import tkinter as tk
port=1234
ADDRESS= '192.168.1.51'

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

window=tk.Tk()
window.title("Digging Bot")
window.geometry("400x400")

def read(w):
    #print(w.keysym)
    print(w)
    b=bytes(w.keysym,'utf-8')
    s.sendto(b,(ADDRESS,port))

def lat123():
    lat1=lat.get()
    print(lat1)
    c=bytes(lat1,'utf-8')
    s.sendto(c,(ADDRESS,port))

def lon123():
    lon1=lon.get()
    print(lon1)
    d=bytes(lon1,'utf-8')
    s.sendto(d,(ADDRESS,port))

title = tk.Label(text="ENTER THE DIRECTION")
title.grid()
dir1 = tk.Entry()
dir1.grid(column=2,row=0)
dir1.bind('<Key>',read)


title =tk.Label(text="ENTER LAT")
lat = tk.Entry()
lat.grid(column=0,row=1)

title =tk.Label(text="ENTER LON")
lon = tk.Entry()
lon.grid(column=2,row=1)

button_1= tk.Button(text="OK", command=lat123)
button_1.grid(column=0,row=2)

button_2= tk.Button(text="OK",command=lon123)
button_2.grid(column=2,row=2)

window.mainloop()
