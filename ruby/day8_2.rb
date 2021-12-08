# I shouldn't have tried to golf that part, and there are better and faster ways
# of doing it
h=[119,18,93,91,58,107,111,82,127,123].zip(0..).to_h;p$<.sum{|l|(0..6).to_a.permutation.map{|t|x=->w{i=0;w.each_char{i|=1<<t[_1.ord-97]};h[i]};f,r=l.split(?|).map &:split;(f.all?x)&&(r.map(&x)*'').to_i}.find{_1}}


# 0 : 119
# 1 : 18
# 2 : 93
# 3 : 91
# 4 : 58
# 5 : 107
# 6 : 111
# 7 : 82
# 8 : 127
# 9 : 123