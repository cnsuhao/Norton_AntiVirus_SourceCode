$! TREQ.COM  --  Tests req keys
$
$	__arch := VAX
$	if f$getsyi("cpu") .ge. 128 then __arch := AXP
$	exe_dir := sys$disk:[-.'__arch'.exe.apps]
$
$	cmd := mcr 'exe_dir'openssl req -config [-.apps]openssl-vms.cnf
$
$	t := testreq.pem
$	if p1 .nes. "" then t = p1
$
$	write sys$output "testing req conversions"
$	copy 't' fff.p
$
$	write sys$output "p -> d"
$	'cmd' -in fff.p -inform p -outform d -out f.d
$	if $severity .ne. 1 then exit 3
$!	write sys$output "p -> t"
$!	'cmd' -in fff.p -inform p -outform t -out f.t
$!	if $severity .ne. 1 then exit 3
$	write sys$output "p -> p"
$	'cmd' -in fff.p -inform p -outform p -out f.p
$	if $severity .ne. 1 then exit 3
$
$	write sys$output "d -> d"
$	'cmd' -verify -in f.d -inform d -outform d -out ff.d1
$	if $severity .ne. 1 then exit 3
$!	write sys$output "t -> d"
$!	'cmd' -verify -in f.t -inform t -outform d -out ff.d2
$!	if $severity .ne. 1 then exit 3
$	write sys$output "p -> d"
$	'cmd' -verify -in f.p -inform p -outform d -out ff.d3
$	if $severity .ne. 1 then exit 3
$
$!	write sys$output "d -> t"
$!	'cmd' -in f.d -inform d -outform t -out ff.t1
$!	if $severity .ne. 1 then exit 3
$!	write sys$output "t -> t"
$!	'cmd' -in f.t -inform t -outform t -out ff.t2
$!	if $severity .ne. 1 then exit 3
$!	write sys$output "p -> t"
$!	'cmd' -in f.p -inform p -outform t -out ff.t3
$!	if $severity .ne. 1 then exit 3
$
$	write sys$output "d -> p"
$	'cmd' -in f.d -inform d -outform p -out ff.p1
$	if $severity .ne. 1 then exit 3
$!	write sys$output "t -> p"
$!	'cmd' -in f.t -inform t -outform p -out ff.p2
$!	if $severity .ne. 1 then exit 3
$	write sys$output "p -> p"
$	'cmd' -in f.p -inform p -outform p -out ff.p3
$	if $severity .ne. 1 then exit 3
$
$	difference/output=nl: fff.p f.p
$	if $severity .ne. 1 then exit 3
$	difference/output=nl: fff.p ff.p1
$	if $severity .ne. 1 then exit 3
$!	difference/output=nl: fff.p ff.p2
$!	if $severity .ne. 1 then exit 3
$	difference/output=nl: fff.p ff.p3
$	if $severity .ne. 1 then exit 3
$
$!	difference/output=nl: f.t ff.t1
$!	if $severity .ne. 1 then exit 3
$!	difference/output=nl: f.t ff.t2
$!	if $severity .ne. 1 then exit 3
$!	difference/output=nl: f.t ff.t3
$!	if $severity .ne. 1 then exit 3
$
$	difference/output=nl: f.p ff.p1
$	if $severity .ne. 1 then exit 3
$!	difference/output=nl: f.p ff.p2
$!	if $severity .ne. 1 then exit 3
$	difference/output=nl: f.p ff.p3
$	if $severity .ne. 1 then exit 3
$
$	delete f.*;*,ff.*;*,fff.*;*
