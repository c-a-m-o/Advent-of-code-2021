c=0
h=Hash.new 0
p $<.sum{
  a,c,b,d=_1.scan(/\d+/).map &:to_i;a,b=[a,b].sort;c,d=[c,d].sort;


  if a == b
    (c..d).count{|x|(h[[a,x]]+=1)==2}
  elsif c==d
    (a..b).count{|y|(h[[y,c]]+=1)==2}
  else
    0
  end
}

