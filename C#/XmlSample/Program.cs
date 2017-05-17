using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace XmlSample
{
    class Program
    {
        static void Main(string[] args)
        {
            var option = new XElement("option");
            option.SetElementValue("enabled", true);
            option.SetElementValue("min", 0);
            option.SetElementValue("max", 100);

            option.SetAttributeValue("visible", true);

            var root = new XElement("settings", option);
            root.Save("sample.xml");
        }
    }
}
