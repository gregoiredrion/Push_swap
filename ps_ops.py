from tkinter import *

def sa_sb(canvas, c_list, marge):
    canvas.move(c_list[0], 0, marge)
    canvas.move(c_list[1], 0, -marge)

    save = c_list[0]
    c_list[0] = c_list[1]
    c_list[1] = save

def ss(lc, rc, c_list_a, c_list_b, marge):
    sa_sb(lc.canvas, c_list_a, marge)
    sa_sb(rc.canvas, c_list_b, marge)

def pa(lc, rc, c_list_a, c_list_b, marge, dico):
    for x in c_list_a:
        lc.move(x, 0, marge)
    new = lc.create_rectangle(100, 100, 100 + dico[c_list_b[0]+500], 100 + marge, outline="#006400", fill="#006400")
    lc.pack(fill=BOTH, expand=1)
    c_list_a.insert(0, new)
    rc.delete(c_list_b[0])
    c_list_b.pop(0)
    for x in c_list_b:
        rc.move(x, 0, -marge)

def pb(lc, rc, c_list_a, c_list_b, marge, dico):
    for x in c_list_b:
        rc.move(x, 0, marge)
    new = rc.create_rectangle(500, 100, 500 - dico[c_list_a[0]], 100 + marge, outline="#0000FF", fill="#0000FF")
    dico[new + 500] = dico[c_list_a[0]]
    rc.pack(fill=BOTH, expand=1)
    c_list_b.insert(0, new)
    lc.delete(c_list_a[0])
    c_list_a.pop(0)
    for x in c_list_a:
        lc.move(x, 0, -marge)

def ra_rb(canvas, c_list, marge):
   c_len  = len(c_list) - 1
   for c in c_list:
       if c == c_list[0]:
           canvas.move(c, 0, (c_len * marge))
       else:
           canvas.move(c, 0, -marge)
   c_list.insert(len(c_list), c_list.pop(0))

def rra_rrb(canvas, c_list, marge):
    c_len = len(c_list) - 1
    for c in c_list:
        if c == c_list[int(c_len)]:
            canvas.move(c, 0, -c_len * marge)
        else:
            canvas.move(c, 0, marge)
    c_list.insert(0, c_list.pop(c_len))

def rr(lc, rc, c_list_a, c_list_b, marge):
    ra_rb(lc.canvas, c_list_a, marge)
    ra_rb(rc.canvas, c_list_b, marge)

def rrr(lc, rc, c_list_a, c_list_b, marge):
    rra_rrb(lc.canvas, c_list_a, marge)
    rra_rrb(rc.canvas, c_list_b, marge)

def display_ops(frame, leftCanvas, rightCanvas, c_list_a, c_list_b, op, dico, marge):
    if (op == "sa"):
        sa_sb(leftCanvas.canvas, c_list_a, marge)
    elif (op == "sb"):
        sa_sb(rightCanvas.canvas, c_list_b, marge)
    elif (op == "ss"):
        ss(leftCanvas, rightCanvas, c_list_a, c_list_b, marge)
    elif (op == "pa"):
        pa(leftCanvas.canvas, rightCanvas.canvas, c_list_a, c_list_b, marge, dico)
    elif (op == "pb"):
        pb(leftCanvas.canvas, rightCanvas.canvas, c_list_a, c_list_b, marge, dico)
    elif (op == "ra"):
        ra_rb(leftCanvas.canvas, c_list_a, marge)
    elif (op == "rb"):
        ra_rb(rightCanvas.canvas, c_list_b, marge)
    elif (op == "rr"):
        rr(leftCanvas, rightCanvas, c_list_a, c_list_b, marge)
    elif (op== "rra"):
        rra_rrb(leftCanvas.canvas, c_list_a, marge)
    elif (op == "rrb"):
        rra_rrb(rightCanvas.canvas, c_list_b, marge)
    else:
        rrr(leftCanvas, rightCanvas, c_list_a, c_list_b, marge)
