#!/usr/bin/env python
# coding: utf-8

# In[19]:


import pandas as pd


# In[20]:


from matplotlib import pyplot as plt


# In[21]:


csv = pd.read_csv("C:/Users/aldoa/Desktop/project/data3.csv")
a = csv.columns
csv.columns = ["NAME", "NUMBER", "ROOM", "TENDENCY", "COST", "DATE"]
csv


# In[22]:


mon1 = 0
tue1 = 0
wed1 = 0
thu1 = 0
fri1 = 0
sat1 = 0
sun1 = 0
mon2 = 0
tue2 = 0
wed2 = 0
thu2 = 0
fri2 = 0
sat2 = 0
sun2 = 0
mon3 = 0
tue3 = 0
wed3 = 0
thu3 = 0
fri3 = 0
sat3 = 0
sun3 = 0
for row in csv.index:
    i = csv.DATE.iloc[row]
    i = i[0:3]
    if csv.TENDENCY.iloc[row] == "Work":
        if i == "Mon":
            mon1 = mon1 + 1
        elif i == "Tue":
            tue1 = tue1 + 1
        elif i == "Wed":
            wed1 = wed1 + 1
        elif i == "Thu":
            thu1 = thu1 + 1
        elif i == "Fri":
            fri1 = fri1 + 1
        elif i == "Sat":
            sat1 = sat1 + 1
        elif i == "Sun":
            sun1 = sun1 + 1
    elif csv.TENDENCY.iloc[row] == "Vacation":
        if i == "Mon":
            mon2 = mon2 + 1
        elif i == "Tue":
            tue2 = tue2 + 1
        elif i == "Wed":
            wed2 = wed2 + 1
        elif i == "Thu":
            thu2 = thu2 + 1
        elif i == "Fri":
            fri2 = fri2 + 1
        elif i == "Sat":
            sat2 = sat2 + 1
        elif i == "Sun":
            sun2 = sun2 + 1
    else:
        if i == "Mon":
            mon3 = mon3 + 1
        elif i == "Tue":
            tue3 = tue3 + 1
        elif i == "Wed":
            wed3 = wed3 + 1
        elif i == "Thu":
            thu3 = thu3 + 1
        elif i == "Fri":
            fri3 = fri3 + 1
        elif i == "Sat":
            sat3 = sat3 + 1
        elif i == "Sun":
            sun3 = sun3 + 1


# In[24]:


x = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
y = [mon1, tue1, wed1, thu1, fri1, sat1, sun1]
z = [mon2, tue2, wed2, thu2, fri2, sat2, sun2]
a = [mon3, tue3, wed3, thu3, fri3, sat3, sun3]
plt.plot(x, y)
plt.plot(x, z)
plt.plot(x, a)
plt.title("Title")
plt.xlabel("Days")
plt.ylabel("Number of People")
plt.legend(["Work", "Vacation", "Others"])
plt.show()


# In[ ]:
