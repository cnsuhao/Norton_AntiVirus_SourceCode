$! TX509.COM  --  Tests x509 certificates
$
$	__arch := VAX
$	if f$getsyi("cpu") .ge. 128 then __arch := AXP
$	exe_dir := sys$disk:[-.'__arch'.exe.apps]
$
$	cmd := mcr 'exe_dir'openssl x509
$
$	t := testx509.pem
$	if p1 .nes. "" then t = p1
$
$	write sys$output "testing X509 conversions"
$	copy 't' fff.p
$
$	write sys$output "p -> d"
$	'cmd' -in fff.p -inform p -outform d -out f.d
$	if $severity .ne. 1 then exit 3
$	write sys$output "p -> n"
$	'cmd' -in fff.p -inform p -outform n -out f.n
$	if $severity .ne. 1 then exit 3
$	write sys$output "p -> p"
$	'cmd' -in fff.p -inform p -outform p -out f.p
$	if $severity .ne. 1 then exit 3
$
$	write sys$output "d -> d"
$	'cmd' -in f.d -inform d -outform d -out ff.d1
$	if $severity .ne. 1 then exit 3
$	write sys$output "n -> d"
$	'cmd' -in f.n -inform n -outform d -out ff.d2
$	if $severity .ne. 1 then exit 3
$	write sys$output "p -> d"
$	'cmd' -in f.p -inform p -outform d -out ff.d3
$	if $severity .ne. 1 then exit 3
$
$	write sys$output "d -> n"
$	'cmd' -in f.d -inform d -outform n -out ff.n1
$	if $severity .ne. 1 then exit 3
$	write sys$output "n -> n"
$	'cmd' -in f.n -inform n -outform n -out ff.n2
$	if $severity .ne. 1 then exit 3
$	write sys$output "p -> n"
$	'cmd' -in f.p -inform p -outform n -out ff.n3
$	if $severity .ne. 1 then exit 3
$
$	write sys$output "d -> p"
$	'cmd' -in f.d -inform d -outform p -out ff.p1
$	if $severity .ne. 1 then exit 3
$	write sys$output "n -> p"
$	'cmd' -in f.n -inform n -outform p -out ff.p2
$	if $severity .ne. 1 then exit 3
$	write sys$output "p -> p"
$	'cmd' -in f.p -inform p -outform p -out ff.p3
$	if $severity .ne. 1 then exit 3
$
$	difference/output=nl: fff.p f.p
$	if $severity .ne. 1 then exit 3
$	difference/output=nl: fff.p ff.p1
$	if $severity .ne. 1 then exit 3
$	difference/output=nl: fff.p ff.p2
$	if $severity .ne. 1 then exit 3
$	difference/output=nl: fff.p ff.p3
$	if $severity .ne. 1 then exit 3
$
$	difference/output=nl: f.n ff.n1
$	if $severity .ne. 1 then exit 3
$	difference/output=nl: f.n ff.n2
$	if $severity .ne. 1 then exit 3
$	difference/output=nl: f.n ff.n3
$	if $severity .ne. 1 then exit 3
$
$	difference/output=nl: f.p ff.p1
$	if $severity .ne. 1 then exit 3
$	difference/output=nl: f.p ff.p2
$	if $severity .ne. 1 then exit 3
$	difference/output=nl: f.p ff.p3
$	if $severity .ne. 1 then exit 3
$
$	delete f.*;*,ff.*;*,fff.*;*
