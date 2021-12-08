t=eval"_="+gets;p (t.min..t.max).map{|i|t.sum{d=(_1-i).abs;d*(d+1)/2}}.min
