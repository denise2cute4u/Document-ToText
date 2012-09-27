#!/usr/bin/perl

use strict;
use warnings;

use Module::Build::WithXSpp;

my $build = Module::Build::WithXSpp->new( extra_typemap_modules => { 'ExtUtils::Typemap::ObjectMap' => '0.01' },
                                                        license => 'perl',
                                                    module_name => 'Text::Convert::Plugin::WPS',
                                                       requires => {} )->create_build_script;