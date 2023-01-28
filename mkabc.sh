if [ $# -ne 1 ]; then
    echo "Usage: $0 XXX"
    exit 1
fi

mkdir -p ABC/abc$1

cp -n template.cpp ABC/abc$1/a.cpp
cp -n template.cpp ABC/abc$1/b.cpp
cp -n template.cpp ABC/abc$1/c.cpp
cp -n template.cpp ABC/abc$1/d.cpp
cp -n template.cpp ABC/abc$1/e.cpp
cp -n template.cpp ABC/abc$1/f.cpp
cp -n template.cpp ABC/abc$1/g.cpp
cp -n template.cpp ABC/abc$1/h.cpp

exit 0