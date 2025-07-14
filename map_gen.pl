#!/usr/bin/perl

use warnings;
use strict;
my ($x, $y, $density, $pattern);
die "program x y density (optional pattern)\n" unless (scalar(@ARGV) == 3 || scalar(@ARGV) == 4);

if (scalar(@ARGV) == 4) {
	($x, $y, $density, $pattern) = @ARGV;
	die "pattern must me 3 characters long" unless (length($pattern) == 3);
}
else {
	($x, $y, $density) = @ARGV;
	$pattern = ".ox";
}
print "$y$pattern\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print substr($pattern, 1, 1);  # Second character (obstacle)
		}
		else {
			print substr($pattern, 0, 1);  # First character (empty)
		}
	}
	print "\n";
}
