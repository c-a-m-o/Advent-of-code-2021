n=eval'_='+gets;b=$<.read.split($/*2).map{_1.split.map &:to_i};r=0..4;(0..n.size).find{|i|c=b.find{|c|l=->k{k.count{n[0..i].index c[_1]}>4};r.find{|x|l[r.map{_1+x*5}]||l[r.map{_1*5+x}]}};p (c.sum-c.filter{n[0..i].index _1}.sum)*n[i]if c}