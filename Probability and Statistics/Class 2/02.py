import pandas as pd
data = {
    "age" : [60,17,45,56,25,53],
    "score" : [5,3,6,1,7,5]
}
df = pd.DataFrame(data,index=["stage 1","stage 2","stage 3","stage 4","stage 5","stage 6"])
print(df.info())