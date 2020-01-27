from tkinter import *
from ps_ops import *
from time import sleep, time

restart = False
speed = 100
play = True
pace = 1

def fill_pile(content):
    pile = []
    ret = ''

    for i in content:
        if (i == ' ' or i == '\n'):
            int_ret = int(ret)
            pile.append(int_ret)
            ret = ''
        if i == '\n':
            index = content.index('\n')
            content = content[index + 1:]
            break
        else:
            ret = ret + i
    return pile, content

def fill_ops(content):
    ops = []
    ret = ''

    for i in content:
        if (i == '\n'):
            ops.append(ret)
            ret = ''
        else:
            ret = ret + i
    return ops

def fill_dico(end_a):
    dico = {}
    value = 450 / len(end_a)
    save = value

    for i in end_a:
        dico[i] = value
        value += save
    return dico

def read_file(file):
    content = file.read()
    a, content = fill_pile(content)
    sorted_a, content = fill_pile(content)
    ops = fill_ops(content)
    return a, sorted_a, ops

def faster():
    global speed
    global app
    global pace

    if pace == 32:
        return
    pace *= 2
    fast = Label(app.bottomFrame, text="Speed = x" + str(pace))
    fast.grid(row=0, column=2)
    speed /= 2

def slower():
    global speed
    global app
    global pace

    if pace == 0.125:
        return
    pace /= 2
    speed *= 2
    slow = Label(app.bottomFrame, text="Speed = x" + str(pace))
    slow.grid(row=0, column=2)


def pauseplay():
    global play

    if (play == True):
        play = False
    else:
        play = True

def exit_gui():
    exit()

def bottom_Buttons(bottomFrame):
    global restartButton

    slowButton = Button(bottomFrame, text="<<", command=slower)
    fastButton = Button(bottomFrame, text=">>", command=faster)
    lastop = Label(bottomFrame, text="Last operations:     ")
    playpause = Button(bottomFrame, text="Play/Pause", command=pauseplay)
    exitButton = Button(bottomFrame, text="Exit", command=exit_gui)
    restartButton = Button(bottomFrame, text="Restart", command=restart_display)
    speedText = Label(bottomFrame, text="Speed = x1")

    lastop.grid(row=0, column=0)
    bottomFrame.grid_columnconfigure(1, minsize=100)
    speedText.grid(row=0, column=2)
    bottomFrame.grid_columnconfigure(2, minsize=110)
    bottomFrame.grid_columnconfigure(3, minsize=195)
    slowButton.grid(row=0, column=4)
    playpause.grid(row=0, column=5)
    fastButton.grid(row=0, column=6)
    bottomFrame.grid_columnconfigure(7, minsize=405)
    restartButton.grid(row=0, column=8)
    exitButton.grid(row=0, column=9)

def display_pile_a(lc, dico, marge):
    add = 0
    pile = []
    new_dico = {}

    for x in lc.pile:
        new = lc.canvas.create_rectangle(lc.start[0], lc.start[1] + add, lc.start[0] + dico[x], lc.start[1] + add + marge, outline="#FF0000", fill="#FF0000")
        pile.append(new)
        lc.canvas.pack(fill=BOTH, expand=1)
        add += marge
        new_dico[new] = x
    for i in new_dico:
        new_dico[i] = dico[new_dico[i]]
    return pile, new_dico

def display_pile_b(rc, dico, marge):
    add = 0
    pile = []
    rc.canvas.create_rectangle(rc.start[0], rc.start[1] + add, rc.start[0] - 100, rc.start[1] + add + marge, outline="#000000", fill="#000000")
    rc.canvas.pack(fill=BOTH, expand=1)
    return pile

def restart_display():
    global app
    global rightCanvas
    global leftCanvas
    global root
    global dico
    global marge
    global ops
    global a
    global restart
    global restartButton

    restartButton.config(state='disabled')
    restartButton.after(1000, lambda: restartButton.config(state='active'))
    restart = False
    leftCanvas.canvas.destroy()
    rightCanvas.canvas.destroy()
    leftCanvas = Canvas_ps(app.leftFrame, [100, 100], a)
    rightCanvas = Canvas_ps(app.rightFrame, [500, 100], b)
    start_display(app, root, leftCanvas, rightCanvas, ops, dico, marge)
    restart = True

def increment(i, app, lc, rc, pile_a, pile_b, ops, len_ops, dico, marge):
    global play

    if i == len_ops - 1:
        return i + 1
    if pace > 4:
        stock = pace / 2
    else:
        stock = 0
    for x in range(int(stock)):
        while play == False:
            sleep(1)
        if i + x + 2 == len_ops:
            return len_ops - 1
        display_ops(app.bottomFrame, leftCanvas, rightCanvas, pile_a, pile_b, ops[i + x + 1], dico, marge)
    return i + stock + 1

def start_display(app, root, leftCanvas, rightCanvas, ops, dico, marge):
    global speed
    global play
    global restart

    i = int(0)
    len_ops = len(ops)
    c_list_a, dico = display_pile_a(leftCanvas, dico, marge)
    c_list_b = display_pile_b(rightCanvas, dico, marge)
    lastop = Label(app.bottomFrame, text="Last operation : -")
    lastop.grid(row=0, column=0)
    display(len_ops, lastop, app, root, leftCanvas, rightCanvas, c_list_a, c_list_b, ops, i, dico, marge)

def display(len_ops, lastop, app, root, leftCanvas, rightCanvas, c_list_a, c_list_b, ops, i, dico, marge):
    if i < len_ops:
        if play == True:
            try:
                display_ops(app.bottomFrame, leftCanvas, rightCanvas, c_list_a, c_list_b, ops[i], dico, marge)
                lastop.config(text = "Last operation : " + ops[i])
                sleep(speed/1000)
                i = int(increment(i, app, leftCanvas, rightCanvas, c_list_a, c_list_b, ops, len_ops, dico, marge))
                root.update_idletasks()
                root.update()
            except:
                return
        root.after(int(speed), display, len_ops, lastop, app, root, leftCanvas, rightCanvas, c_list_a, c_list_b, ops, i, dico, marge)

class Canvas_ps():
    def __init__(self, frame, start, pile):
        self.canvas = Canvas(frame, bg="black", width=100)
        self.start = start
        self.pile = pile

class Window(Frame):
    def __init__(self, master=None):
        Frame.__init__(self)
        Frame.configure(self, background = "black")
        self.bottomFrame = Frame(self)
        self.bottomFrame.pack(side=BOTTOM, fill=X)
        self.leftFrame = Frame(self, bg="black", height=100)
        self.leftFrame.pack(side=LEFT, fill=BOTH, expand=1)
        self.rightFrame = Frame(self, bg="black")
        self.rightFrame.pack(side=RIGHT, fill=BOTH, expand=1)
        self.master = master
        self.initialize_window()

    def initialize_window(self):
        self.master.title("Visu push_swap")
        self.pack(fill=BOTH, expand=1)

root = Tk()
root.geometry("1250x1000")
root.resizable(False,False)
app = Window(root)
bottom_Buttons(app.bottomFrame)
f = open("infos.txt", "r")
a, sorted_a, ops = read_file(f)
b = []
leftCanvas = Canvas_ps(app.leftFrame, [100, 100], a)
rightCanvas = Canvas_ps(app.rightFrame, [500, 100], b)
dico = fill_dico(sorted_a)
marge = 800 / len(a)
f.close()

start_display(app, root, leftCanvas, rightCanvas, ops, dico, marge)


app.mainloop()
