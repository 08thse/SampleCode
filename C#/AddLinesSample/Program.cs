using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// ファイルの先頭に行を挿入するサンプル
namespace AddLinesSample
{
    class Program
    {
        static void Main(string[] args)
        {
            // sample.txt はプログラムのフォルダに用意しておく前提
            var filePath = @"sample.txt";

            using (var stream = new FileStream(filePath, FileMode.Open, FileAccess.ReadWrite, FileShare.None))
            {
                // リソース解放などの考慮的には using を使うのをオススメ
                using (var reader = new StreamReader(stream))
                using (var writer = new StreamWriter(stream))
                {
                    string texts = reader.ReadToEnd();
                    stream.Position = 0;
                    writer.WriteLine("Line1");
                    writer.WriteLine("Line2");
                    writer.Write(texts);
                }
            }
        }
    }
}
