Name:		atk
Summary:	Accessibility Toolkit
Version:	2.13.90
Release:	1
License:	LGPL
Group:		Development/Libraries
Source:		ftp://ftp.gimp.org/pub/gtk/v2.6/%{name}-%{version}.tar.gz
BuildRoot:	/var/tmp/%{name}-%{version}-root
URL:		http://www.gtk.org
Requires:	glib2 >= 2.31.2
BuildRequires:	glib2-devel >= 2.31.2

%description
Handy library of accessibility functions. Development libs and headers
are in atk-devel.

%package devel
Summary:	Header, docs and development libraries for atk.
Group:		Development/Libraries
Requires:	%{name} = %{version}

%description devel
Header, docs and development libraries for atk.

%prep
%setup -q

%build
CFLAGS="$RPM_OPT_FLAGS"
./configure --prefix=%{_prefix} \
    --bindir=%{_bindir} --mandir=%{_mandir} \
    --localstatedir=%{_localstatedir} --libdir=%{_libdir} \
    --datadir=%{_datadir} --includedir=%{_includedir} \
    --sysconfdir=%{_sysconfdir} --disable-gtk-doc
make

%install
rm -rf $RPM_BUILD_ROOT

make prefix=$RPM_BUILD_ROOT%{_prefix} bindir=$RPM_BUILD_ROOT%{_bindir} \
    mandir=$RPM_BUILD_ROOT%{_mandir} libdir=$RPM_BUILD_ROOT%{_libdir} \
    localstatedir=$RPM_BUILD_ROOT%{_localstatedir} \
    datadir=$RPM_BUILD_ROOT%{_datadir} \
    includedir=$RPM_BUILD_ROOT%{_includedir} \
    sysconfdir=$RPM_BUILD_ROOT%{_sysconfdir} install

%clean
rm -rf $RPM_BUILD_ROOT

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(-, root, root)

%doc AUTHORS COPYING ChangeLog NEWS README
%{_libdir}/lib*.so.*

%files devel
%defattr(-, root, root)

%{_libdir}/lib*.so
%{_libdir}/*a
%{_libdir}/pkgconfig/*.pc
%{_includedir}/atk-1.0
%{_datadir}/gtk-doc/html/atk
%{_datadir}/locale/*/*

%changelog
* Wed Feb 23 2005 Padraig O'Briain <padraig.obriain@sun.com>
- Updated  version number in Source from 1.3 to 2.6.
- Corrceted spelling of Accessibility

* Fri Jun 20 2003 James T. Richardson, Jr. <james@richardsons.us>
- Updated for atk-1.3.2
  added: {_datadir}/locale/*/*

* Mon Aug 27 2001 Jens Finke <jens@gnome.org>
- glib2 package now required
- updated source url

* Wed Aug 15 2001 Jens Finke <jens@gnome.org>
- created spec file
