#!/usr/bin/perl

$first = 1;

while (<>) {
	($n, $name) = $_ =~ /^\s*(\d+)\s+(\S+)\s/;
	if (	($name eq ".text") ||
		($name eq ".rodata") ||
		($name eq ".data") ||
		($name eq ".bss")) {
		if ($first) {
			print " ...\n";
		}
		print "$_";
		$_ = <>;
		print "$_";
		print " ...\n";
		$first = 0;
	}
}
