t=[0]*9;eval("_="+gets).map{t[_1]+=1};256.times{t[7]+=t[0];t.rotate!};p t.sum