# CherryTree

Origin Website: http://www.giuspen.com/cherrytree/

# Install CherryTree Dev

## Install Dependencies

```sh
sudo apt-get install -y python-dev python-pip

sudo apt-get install -y p7zip-full python-appindicator python-dbus python-enchant python-gtk2 python-gtksourceview2
```

## Clone Source Code and Install Libraries

```sh
git clone https://github.com/cuongtransc/cherrytree

cd cherrytree

sudo pip install -r requirements.txt

# Install
sudo python setup.py install

```

## Run CherryTree

```sh
python cherrytree
```

A hierarchical note taking application, featuring rich text and syntax highlighting, storing data in a single XML or SQLite file.
The project home page is [giuspen.com/cherrytree](https://www.giuspen.com/cherrytree/).

## Getting Started
### Prerequisites
The current (python) version requires:
* python2
* python-gtk2
* python-gtksourceview2
* p7zip-full
* python-dbus
* python-enchant
* python-chardet

Then, after cloning, run in the top folder `./cherrytree` or `python2 cherrytree`.

### Installation
Look at [giuspen.com/cherrytree/#downl](https://www.giuspen.com/cherrytree/#downl) for available installers.

### Development
The development is currently happening on the **master** branch in the folder **future**, being a C++/GTKmm porting.

The latest stable python release is also from the master branch.

The branch **pygi** is a discontinued attempt to port to the python bindings for GTK3. Reason for the failure in the issue [python-gtksourceview2 deprecated, please port to PyGI](https://github.com/giuspen/cherrytree/issues/125).
