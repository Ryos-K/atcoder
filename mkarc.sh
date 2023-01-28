if [ $# -ne 1 ]; then
    echo "Usage: $0 XXX"
    exit 1
fi

mkdir -p ARC/arc$1

cp -n template.cpp ARC/arc$1/a.cpp
cp -n template.cpp ARC/arc$1/b.cpp
cp -n template.cpp ARC/arc$1/c.cpp
cp -n template.cpp ARC/arc$1/d.cpp
cp -n template.cpp ARC/arc$1/e.cpp
cp -n template.cpp ARC/arc$1/f.cpp
cp -n template.cpp ARC/arc$1/g.cpp
cp -n template.cpp ARC/arc$1/h.cpp

exit 0