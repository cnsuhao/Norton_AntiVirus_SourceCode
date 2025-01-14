#!/usr/local/bin/perl

package x86ms;

$label="L000";

%lb=(	'eax',	'al',
	'ebx',	'bl',
	'ecx',	'cl',
	'edx',	'dl',
	'ax',	'al',
	'bx',	'bl',
	'cx',	'cl',
	'dx',	'dl',
	);

%hb=(	'eax',	'ah',
	'ebx',	'bh',
	'ecx',	'ch',
	'edx',	'dh',
	'ax',	'ah',
	'bx',	'bh',
	'cx',	'ch',
	'dx',	'dh',
	);

sub main'asm_init_output { @out=(); }
sub main'asm_get_output { return(@out); }
sub main'get_labels { return(@labels); }
sub main'external_label { push(@labels,@_); }

sub main'LB
	{
	(defined($lb{$_[0]})) || die "$_[0] does not have a 'low byte'\n";
	return($lb{$_[0]});
	}

sub main'HB
	{
	(defined($hb{$_[0]})) || die "$_[0] does not have a 'high byte'\n";
	return($hb{$_[0]});
	}

sub main'BP
	{
	&get_mem("BYTE",@_);
	}

sub main'DWP
	{
	&get_mem("DWORD",@_);
	}

sub main'BC
	{
	return @_;
	}

sub main'DWC
	{
	return @_;
	}

sub main'stack_push
	{
	local($num)=@_;
	$stack+=$num*4;
	&main'sub("esp",$num*4);
	}

sub main'stack_pop
	{
	local($num)=@_;
	$stack-=$num*4;
	&main'add("esp",$num*4);
	}

sub get_mem
	{
	local($size,$addr,$reg1,$reg2,$idx)=@_;
	local($t,$post);
	local($ret)="$size PTR ";

	$addr =~ s/^\s+//;
	if ($addr =~ /^(.+)\+(.+)$/)
		{
		$reg2=&conv($1);
		$addr="_$2";
		}
	elsif ($addr =~ /^[_a-zA-Z]/)
		{
		$addr="_$addr";
		}

	$reg1="$regs{$reg1}" if defined($regs{$reg1});
	$reg2="$regs{$reg2}" if defined($regs{$reg2});
	if (($addr ne "") && ($addr ne 0))
		{
		if ($addr !~ /^-/)
			{ $ret.=$addr; }
		else	{ $post=$addr; }
		}
	if ($reg2 ne "")
		{
		$t="";
		$t="*$idx" if ($idx != 0);
		$reg1="+".$reg1 if ("$reg1$post" ne "");
		$ret.="[$reg2$t$reg1$post]";
		}
	else
		{
		$ret.="[$reg1$post]"
		}
	return($ret);
	}

sub main'mov	{ &out2("mov",@_); }
sub main'movb	{ &out2("mov",@_); }
sub main'and	{ &out2("and",@_); }
sub main'or	{ &out2("or",@_); }
sub main'shl	{ &out2("shl",@_); }
sub main'shr	{ &out2("shr",@_); }
sub main'xor	{ &out2("xor",@_); }
sub main'xorb	{ &out2("xor",@_); }
sub main'add	{ &out2("add",@_); }
sub main'adc	{ &out2("adc",@_); }
sub main'sub	{ &out2("sub",@_); }
sub main'rotl	{ &out2("rol",@_); }
sub main'rotr	{ &out2("ror",@_); }
sub main'exch	{ &out2("xchg",@_); }
sub main'cmp	{ &out2("cmp",@_); }
sub main'lea	{ &out2("lea",@_); }
sub main'mul	{ &out1("mul",@_); }
sub main'div	{ &out1("div",@_); }
sub main'dec	{ &out1("dec",@_); }
sub main'inc	{ &out1("inc",@_); }
sub main'jmp	{ &out1("jmp",@_); }
sub main'jmp_ptr { &out1p("jmp",@_); }
sub main'je	{ &out1("je",@_); }
sub main'jle	{ &out1("jle",@_); }
sub main'jz	{ &out1("jz",@_); }
sub main'jge	{ &out1("jge",@_); }
sub main'jl	{ &out1("jl",@_); }
sub main'jb	{ &out1("jb",@_); }
sub main'jc	{ &out1("jc",@_); }
sub main'jnc	{ &out1("jnc",@_); }
sub main'jnz	{ &out1("jnz",@_); }
sub main'jne	{ &out1("jne",@_); }
sub main'jno	{ &out1("jno",@_); }
sub main'push	{ &out1("push",@_); $stack+=4; }
sub main'pop	{ &out1("pop",@_); $stack-=4; }
sub main'bswap	{ &out1("bswap",@_); &using486(); }
sub main'not	{ &out1("not",@_); }
sub main'call	{ &out1("call",'_'.$_[0]); }
sub main'ret	{ &out0("ret"); }
sub main'nop	{ &out0("nop"); }

sub out2
	{
	local($name,$p1,$p2)=@_;
	local($l,$t);

	push(@out,"\t$name\t");
	$t=&conv($p1).",";
	$l=length($t);
	push(@out,$t);
	$l=4-($l+9)/8;
	push(@out,"\t" x $l);
	push(@out,&conv($p2));
	push(@out,"\n");
	}

sub out0
	{
	local($name)=@_;

	push(@out,"\t$name\n");
	}

sub out1
	{
	local($name,$p1)=@_;
	local($l,$t);

	push(@out,"\t$name\t".&conv($p1)."\n");
	}

sub conv
	{
	local($p)=@_;

	$p =~ s/0x([0-9A-Fa-f]+)/0$1h/;
	return $p;
	}

sub using486
	{
	return if $using486;
	$using486++;
	grep(s/\.386/\.486/,@out);
	}

sub main'file
	{
	local($file)=@_;

	local($tmp)=<<"EOF";
	TITLE	$file.asm
        .386
.model FLAT
EOF
	push(@out,$tmp);
	}

sub main'function_begin
	{
	local($func,$extra)=@_;

	push(@labels,$func);

	local($tmp)=<<"EOF";
_TEXT	SEGMENT
PUBLIC	_$func
$extra
_$func PROC NEAR
	push	ebp
	push	ebx
	push	esi
	push	edi
EOF
	push(@out,$tmp);
	$stack=20;
	}

sub main'function_begin_B
	{
	local($func,$extra)=@_;

	local($tmp)=<<"EOF";
_TEXT	SEGMENT
PUBLIC	_$func
$extra
_$func PROC NEAR
EOF
	push(@out,$tmp);
	$stack=4;
	}

sub main'function_end
	{
	local($func)=@_;

	local($tmp)=<<"EOF";
	pop	edi
	pop	esi
	pop	ebx
	pop	ebp
	ret
_$func ENDP
_TEXT	ENDS
EOF
	push(@out,$tmp);
	$stack=0;
	%label=();
	}

sub main'function_end_B
	{
	local($func)=@_;

	local($tmp)=<<"EOF";
_$func ENDP
_TEXT	ENDS
EOF
	push(@out,$tmp);
	$stack=0;
	%label=();
	}

sub main'function_end_A
	{
	local($func)=@_;

	local($tmp)=<<"EOF";
	pop	edi
	pop	esi
	pop	ebx
	pop	ebp
	ret
EOF
	push(@out,$tmp);
	}

sub main'file_end
	{
	push(@out,"END\n");
	}

sub main'wparam
	{
	local($num)=@_;

	return(&main'DWP($stack+$num*4,"esp","",0));
	}

sub main'swtmp
	{
	return(&main'DWP($_[0]*4,"esp","",0));
	}

# Should use swtmp, which is above esp.  Linix can trash the stack above esp
#sub main'wtmp
#	{
#	local($num)=@_;
#
#	return(&main'DWP(-(($num+1)*4),"esp","",0));
#	}

sub main'comment
	{
	foreach (@_)
		{
		push(@out,"\t; $_\n");
		}
	}

sub main'label
	{
	if (!defined($label{$_[0]}))
		{
		$label{$_[0]}="\$${label}${_[0]}";
		$label++;
		}
	return($label{$_[0]});
	}

sub main'set_label
	{
	if (!defined($label{$_[0]}))
		{
		$label{$_[0]}="${label}${_[0]}";
		$label++;
		}
	push(@out,"$label{$_[0]}:\n");
	}

sub main'data_word
	{
	push(@out,"\tDD\t$_[0]\n");
	}

sub out1p
	{
	local($name,$p1)=@_;
	local($l,$t);

	push(@out,"\t$name\t ".&conv($p1)."\n");
	}
