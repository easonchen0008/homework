# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import pandas as pd
import numpy as np
usecols = ['High school system','Gender','Num of graduates','Num of enroll in National university','Num of enroll in private university','Num of enroll in police university','Num of enroll in police college','Num of enroll in military school','Num of enroll in other school']
df = pd.read_csv('mycsvfile.csv', usecols=usecols)
new_df = df.dropna()
print(new_df)