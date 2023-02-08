# bash locals arent particularly local are they...

function t1 {
	local x=1
	t2 $x
}

function t2 {
	echo x $x
}

t1
