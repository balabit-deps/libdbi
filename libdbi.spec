%define name	libdbi
%define version	0.5
%define release 1

Summary:	Database Independent Abstraction Layer for C
Name:		%{name}
Version:	%{version}
Release:	%{release}
Group:		Development/Libraries
Copyright:	LGPL
URL:		http://libdbi.sourceforge.net/
Vendor:		Neon Goat Productions
Packager:	David A. Parker <david@neongoat.com>
Source:		%{name}-%{version}.tar.gz
BuildRoot:	%{_tmppath}/%{name}-root

%description
libdbi implements a database-independent abstraction layer in C, similar to the
DBI/DBD layer in Perl. Writing one generic set of code, programmers can
leverage the power of multiple databases and multiple simultaneous database
connections by using this framework.

%package devel
Summary: Development files for libdbi (Database Independent Abstraction Layer for C)
Group: Development/Libraries
Requires:	%{name} = %{version}-%{release}

%description devel
The libdbi-devel package contains the header files and documentation
needed to develop applications with libdbi.

%package dbd-mysql
Summary: MySQL plugin for libdbi
Group: Development/Libraries
Requires:	%{name} = %{version}-%{release}, mysqlclient9 >= 3.23.22

%description dbd-mysql
This plugin provides connectivity to MySQL database servers through the
libdbi database independent abstraction layer. Switching a program's plugin
does not require recompilation or rewriting source code.

%package dbd-pgsql
Summary: PostgreSQL plugin for libdbi
Group: Development/Libraries
Requires:	%{name} = %{version}-%{release}, postgresql >= 7.0.3

%description dbd-pgsql
This plugin provides connectivity to PostgreSQL database servers through the
libdbi database independent abstraction layer. Switching a program's plugin
does not require recompilation or rewriting source code.

%prep
%setup -q -n %{name}-%{version}

%build
CFLAGS="$RPM_OPT_FLAGS" ./configure --prefix=/usr --with-mysql --with-pgsql
make

%install
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install

%files
%defattr(-,root,root)
%doc AUTHORS
%doc COPYING
%doc README
%doc PLUGINS
/usr/lib/libdbi.so.*

%files devel
%doc README
%doc TODO
%doc doc/programmers-guide.pdf
%doc doc/programmers-guide/
/usr/include/dbi/dbi.h
/usr/include/dbi/dbi-dev.h
/usr/include/dbi/dbd.h
/usr/lib/libdbi.a
/usr/lib/libdbi.la
/usr/lib/libdbi.so

%files dbd-mysql
/usr/lib/dbd/libmysql.so
/usr/lib/dbd/libmysql.la

%files dbd-pgsql
/usr/lib/dbd/libpgsql.so
/usr/lib/dbd/libpgsql.la

%clean 
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT

%post
/sbin/ldconfig

%postun
/sbin/ldconfig

%changelog
* Sat Aug 4 2001 David Parker <david@neongoat.com>
- initial spec file created
